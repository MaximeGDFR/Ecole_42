/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:11 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 15:31:18 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_coordinates(t_bresenham *bresenham, int *x, int *y)
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

	if (points.x >= 0 && points.x < WIDTH && points.y >= 0 && points.y < HEIGHT)
	{
		index = (points.y * env->img.size_line + points.x * (env->img.bpp / 8));
		*((int *)(env->img.data + index)) = points.color;
	}
	else
		printf("Warning: Coordinates out of bounds for put_pixel: (%d, %d)\n",
			points.x, points.y);
}

void	draw_line_bresenham(t_env *env, t_point p1, t_point p2)
{
	t_bresenham	bresenham;
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

	if (x + 1 < env->width)
	{
		p1 = env->points[y][x];
		p2 = env->points[y][x + 1];
		draw_line_bresenham(env, p1, p2);
	}
	if (y + 1 < env->height)
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

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			draw_lines(env, x, y);
			x++;
		}
		y++;
	}
}
