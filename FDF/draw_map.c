/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:19:44 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/16 21:33:21 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	draw_pixel(t_point point, t_env *env)
{
	int	index;

	if (point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT)
	{
		index = (point.y * env->line_len + point.x * (env->bpp / 8));
		*((int *)(env->data_addr + index)) = point.color;
	}
	else
		printf("Warning: Coordinates out of bounds for put_pixel: (%d, %d)\n",
			point.x, point.y);
}

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
		{
			draw_pixel(current_point, env);
		}
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_coordinates(&bresenham, &p1.x, &p1.y);
	}
}

void	draw_lines(int x1, int x2, int y1, int y2, t_env *env)
{
	t_point	p1;
	t_point	p2;

	p1 = projection(x1, y1, env);
	p2 = projection(x2, y2, env);
	draw_line_bresenham(env, p1, p2);
}

void	draw_map(t_env *env)
{
	int		y;
	int		x;
	t_point	**projected_points;

	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bpp / 8));
	projected_points = apply_projection(env);
	if (!projected_points)
    	handle_error("Error: apply_projection failed to allocate memory.\n", 1);

	printf("Map dimensions: width = %d, height = %d\n",
       env->map->width, env->map->height);
	printf("Camera angles: x_angle = %f, y_angle = %f\n",
       env->cam->x_angle, env->cam->y_angle);

	y = 0;
	if (env->cam->x_angle > 0)
		y = env->map->height - 1;
	printf("Initial y: %d, map height: %d, x_angle: %f\n", y, env->map->height, env->cam->x_angle);
	while (y >= 0 && y < env->map->height)
	{
		x = 0;
		if (env->cam->x_angle > 0)
			x = env->map->width - 1;
		printf("\nStarting new row: y = %d, x = %d\n", y, x);
		while (x >= 0 && x < env->map->width)
		{
			printf("Processing point: (x, y) = (%d, %d)\n", x, y);
			if (x != env->map->width - 1)
				if (x + 1 < env->map->width)
					draw_lines(x, y, x + 1, y, env);
			if (y != env->map->height - 1)
				if (y + 1 < env->map->height)
					draw_lines(x, y, x, y + 1, env);
			printf("x before increment: %d\n", x);
    		x += -2 * (env->cam->y_angle > 0) + 1;
			printf("x after increment: %d\n", x);
		}
		printf("y before increment: %d\n", y);
		y += -2 * (env->cam->x_angle > 0) + 1;
		printf("y after increment: %d\n", y);
	}
	free_projected_points(projected_points, env->map->height);
//	init_menu(env->menu);
//	if (!env->menu)
//	    handle_error("Error: env->menu is NULL.\n", 1);
}

int next_index(int current, int reverse, int max)
{
	printf("current: %d, reverse: %d\n", current, reverse);
    if (reverse)
		current--;
	else
		current++;
	if (current < 0)
		current = 0;
	if (current >= max)
		current = max - 1;
	printf("current: %d, reverse: %d\n", current, reverse);
	return (current);
}*/