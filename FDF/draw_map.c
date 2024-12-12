/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:19:44 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/12 13:50:43 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_pixel(t_point point, t_env *env)
{
    if (point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT)
    {
        int index = (point.y * env->line_len + point.x * (env->bpp / 8));
        *((int *)(env->data_addr + index)) = point.color;
    }
    else
        printf("Warning: Coordinates out of bounds for put_pixel: (%d, %d)\n", point.x, point.y);
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
			put_pixel(current_point, env);
		}
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
		p1 = env->points[y][x];
		p2 = env->points[y][x + 1];
		draw_line_bresenham(env, p1, p2);
	}
	if (y + 1 < env->map->height)
	{
		p1 = env->points[y][x];
		p2 = env->points[y + 1][x];
		draw_line_bresenham(env, p1, p2);
	}
}

void	draw_map(t_env *env)
{
	int	y;
	int	x;

	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bpp / 8));
	y = 0;
	if  (env->cam->x_angle > 0)
		y = env->map->height - 1;
	while (y < env->map->height && y >= 0)
	{
		x = 0;
		if (env->cam->y_angle > 0)
			x = env->map->width - 1;
		while (x < env->map->width && x >= 0)
		{
			if (x != env->map->width - 1)
				draw_lines(projection(x, y, env), projection(x + 1, y, env), env);
			if (y != env->map->height - 1)
				draw_lines(projection(x, y, env), projection(x, y + 1, env), env);
			x += -2 * (env->cam->y_angle > 0) + 1;
		}
		y += -2 * (env->cam->x_angle > 0) + 1;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	init_menu(env->menu);
}
