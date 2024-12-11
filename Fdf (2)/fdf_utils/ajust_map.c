/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajust_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:27:17 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 15:32:55 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_scale(t_env *env)
{
	int	max_map_size;
	int	window_size;
	int	new_tile_size;
	int	padding;

	if (env->width == 0 || env->height == 0)
		handle_error("Invalid map dimensions.\n", 1);
	if (env->width > env->height)
		max_map_size = env->width;
	else
		max_map_size = env->height;
	if (WIDTH < HEIGHT)
		window_size = WIDTH;
	else
		window_size = HEIGHT;
	padding = window_size * 0.2;
	new_tile_size = (window_size - padding) / max_map_size;
	if (new_tile_size < env->tile_size)
		env->tile_size = new_tile_size;
	if (env->tile_size < 1)
		env->tile_size = 1;
}

void	center_map(t_env *env)
{
	double	scale_x;
	double	scale_y;

	scale_x = (WIDTH * SCALE) / (env->x_max - env->x_min);
	scale_y = (HEIGHT * SCALE) / (env->y_max - env->y_min);
	env->scale = fmin(scale_x, scale_y);
	env->x_center = (env->x_min + env->x_max) / 2.0;
	env->y_center = (env->y_min + env->y_max) / 2.0;
	env->x_center_offset = WIDTH / 2 - env->x_center * env->scale;
	env->y_center_offset = HEIGHT / 2 - env->y_center * env->scale;
}

void	apply_center(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			env->points[y][x].x = (env->points[y][x].x - env->x_center)
				* env->scale + WIDTH / 2 + env->x_offset;
			env->points[y][x].y = (env->points[y][x].y - env->y_center)
				* env->scale + HEIGHT / 2 + env->y_offset;
			x++;
		}
		y++;
	}
}

void	update_map_limits(t_env *env, int x, int y)
{
	if (env->points[y][x].x < env->x_min)
		env->x_min = env->points[y][x].x;
	if (env->points[y][x].x > env->x_max)
		env->x_max = env->points[y][x].x;
	if (env->points[y][x].y < env->y_min)
		env->y_min = env->points[y][x].y;
	if (env->points[y][x].y > env->y_max)
		env->y_max = env->points[y][x].y;
}
