/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:03:46 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/22 17:25:05 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	save_map(t_env *env)
{
	int	x;
	int	y;

	env->original_map = malloc(sizeof(t_map));
	if (!env->original_map)
		handle_error("In save_map: original_map malloc failed.\n", 1);
	save_values_map(env);
	env->original_map->matrix = malloc(sizeof(t_point *) * env->map->height);
	if (!env->original_map->matrix)
		handle_error("In save_map: original_map->matrix malloc failed.\n", 1);
	y = 0;
	while (y < env->map->height)
	{
		env->original_map->matrix[y] = malloc(sizeof(t_point)
				* env->map->width);
		if (!env->original_map->matrix[y])
			handle_error("In save_map: original_map row malloc failed.\n", 1);
		x = 0;
		while (x < env->map->width)
		{
			env->original_map->matrix[y][x] = env->map->matrix[y][x];
			x++;
		}
		y++;
	}
}

void	save_values_map(t_env *env)
{
	env->original_map->height = env->map->height;
	env->original_map->width = env->map->width;
	env->original_map->z_min = env->map->z_min;
	env->original_map->z_max = env->map->z_max;
	env->original_map->x_max = env->map->x_max;
	env->original_map->y_max = env->map->y_max;
}

void	reset_values(t_env *env)
{
	env->map->centered = 1;
	env->map->depth = 0.53;
	env->cam->zoom = 39;
	env->cam->x_offset = 667;
	env->cam->y_offset = 394;
	env->cam->iso = 1;
	env->cam->x_angle = -0.615472907;
	env->cam->y_angle = -0.523599;
	env->cam->z_angle = 0.615472907;
	env->cam->z_height = 0.5;
	env->ctrl_pressed = 0;
}

void	reset(t_env *env)
{
	int	x;
	int	y;

	reset_values(env);
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			env->map->matrix[y][x] = env->original_map->matrix[y][x];
			x++;
		}
		y++;
	}
	draw_map(env);
}

