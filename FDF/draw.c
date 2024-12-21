/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:35:30 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/21 14:26:57 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_coordinates(t_algorithm *bresenham, int *x, int *y)
{
	int	err_2;

	err_2 = bresenham->err * 2;
	if (err_2 > -bresenham->dy)
	{
		bresenham->err -= bresenham->dy;
		*x += bresenham->sx;
	}
	if (err_2 < bresenham->dx)
	{
		bresenham->err += bresenham->dx;
		*y += bresenham->sy;
	}
}

void	put_pixel(t_point points, t_env *env)
{
	int	index;

	if (points.color == 0x00000000)
		return ;
	if (points.x >= 0 && points.x < WIDTH && points.y >= 0 && points.y < HEIGHT)
	{
		index = (points.y * env->line_len + points.x * (env->bpp / 8));
		*((int *)(env->data_addr + index)) = points.color;
	}
	else
		handle_error("In put_pixel: coordinates out of bounds.\n", 1);
}

void	draw_line_bresenham(t_env *env, t_point p1, t_point p2)
{
	t_algorithm	bresenham;
	t_point		current_point;

	bresenham.dx = ft_abs(p2.x - p1.x);
	bresenham.dy = ft_abs(p2.y - p1.y);
	bresenham.sx = get_sign(p2.x - p1.x);
	bresenham.sy = get_sign(p2.y - p1.y);
	bresenham.err = bresenham.dx - bresenham.dy;
	while (1)
	{
		current_point.x = p1.x;
		current_point.y = p1.y;
		current_point.z = p1.z;
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
			put_pixel(current_point, env);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_coordinates(&bresenham, &p1.x, &p1.y);
	}
}

void	draw_lines(t_env *env, int x, int y)
{
	t_point	p1;
	t_point	p2;

	if (x + 1 < env->map->width)
	{
		p1 = env->map->matrix[y][x];
		p2 = env->map->matrix[y][x + 1];
		draw_line_bresenham(env, p1, p2);
	}
	if (y + 1 < env->map->height)
	{
		p1 = env->map->matrix[y][x];
		p2 = env->map->matrix[y + 1][x];
		draw_line_bresenham(env, p1, p2);
	}
}

void	draw_map(t_env *env)
{
	int		y;
	int		x;
	t_point	**projected_points;

	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bpp / 8));
	projected_points = apply_projection(env);
	if (!projected_points)
		handle_error("In draw_map: error allocation projected_points.\n", 1);
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			if (x + 1 < env->map->width)
				draw_line_bresenham(env, projected_points[y][x],
					projected_points[y][x + 1]);
			if (y + 1 < env->map->height)
				draw_line_bresenham(env, projected_points[y][x],
					projected_points[y + 1][x]);
			x++;
		}
		y++;
	}
	free_projected_points(projected_points, env->map->height);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	draw_menu(env);
}


void	free_projected_points(t_point **projected_points, int height)
{
	int	y;

	if (!projected_points)
		return ;
	y = 0;
	while (y < height)
	{
		if (projected_points[y])
			free(projected_points[y]);
		y++;
	}
	free(projected_points);
	projected_points = NULL;
}

void	change_projection(t_point *point, t_env *env)
{
	if (env->map->current_view == FRONT_VIEW)
		projection_front(point, env);
	else if (env->map->current_view == TOP_VIEW)
		projection_top(point, env);
	else if (env->map->current_view == RIGHT_VIEW)
		projection_right(point, env);
	else if (env->map->current_view == LEFT_VIEW)
		projection_left(point, env);
	else if (env->map->current_view == ISO_VIEW)
		projection_isometric(point, env);
	else if (env->map->current_view == PERSPECTIVE_VIEW)
		projection_perspective(env, point, 1000);
	else if (env->map->current_view == OBLIQUE_VIEW)
		projection_oblique(env, point, 30.0, OBLIQUE_REDUCTION);
}

void center_map(t_env *env)
{
	int	draw_width;
	int	draw_height;

	if (env->map->current_view != ISO_VIEW)
	{
		draw_width = env->map->width * env->cam->zoom;
		draw_height = env->map->height * env->cam->zoom;
	}
	else
	{
		draw_width = (env->map->width + env->map->height) * env->cam->zoom / 2;
		draw_height = (env->map->width + env->map->height) * env->cam->zoom / 4;
	}
	env->cam->x_offset = (WIDTH - draw_width) / 2;
	env->cam->y_offset = (HEIGHT - draw_height) / 2;
}

t_point	**allocate_projected_points(t_env *env)
{
	int		y;
	t_point	**projected_points;

	if (env->map->height <= 0 || env->map->width <= 0)
		handle_error("Invalid map dimensions.\n", 1);
	projected_points = malloc(env->map->height * sizeof(t_point *));
	if (!projected_points)
		handle_error("Error allocation in apply_projection.\n", 1);
	y = -1;
	while (++y < env->map->height)
	{
		projected_points[y] = malloc(env->map->width * sizeof(t_point));
		if (!projected_points[y])
		{
			while (--y >= 0)
				free(projected_points[y]);
			free(projected_points);
			handle_error("In allocate_projected_points: error allocation.\n",
				1);
			return (NULL);
		}
	}
	return (projected_points);
}

t_point	**apply_projection(t_env *env)
{
	int		y;
	int		x;
	t_point	**projected_points;

	projected_points = allocate_projected_points(env);
	if (!projected_points)
		handle_error("In apply_projection: error allocation.\n", 1);
	if (env->map->centered)
	{
		center_map(env);
		env->map->centered = 0;
	}
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			projected_points[y][x] = env->map->matrix[y][x];
			change_projection(&projected_points[y][x], env);
			x++;
		}
		y++;
	}
	return (projected_points);
}

void	calculate_depth(t_env *env)
{
	float	max_z;
	float	scale_factor;

	max_z = fmaxf(fabs((float)env->map->z_max), fabs((float)env->map->z_min));
	scale_factor = fmaxf(env->map->width, env->map->height);
	env->map->depth = max_z / scale_factor;
}
