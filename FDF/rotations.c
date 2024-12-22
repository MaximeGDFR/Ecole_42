/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:51:07 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/22 15:28:06 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_right(t_env *env)
{
	int		x;
	int		y;
	t_point	*point;
	double	new_x;
	double	new_z;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			point = &env->map->matrix[y][x];
			new_x = point->x * cos(env->cam->y_angle) + point->z
				* sin(env->cam->y_angle);
			new_z = -point->x * sin(env->cam->y_angle) + point->z
				* cos(env->cam->y_angle);
			point->x = (int)new_x;
			point->z = (int)new_z;
			x++;
		}
		y++;
	}
}

void	rotate_left(t_env *env)
{
	int		x;
	int		y;
	t_point	*point;
	double	new_x;
	double	new_z;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			point = &env->map->matrix[y][x];
			new_x = point->x * cos(-env->cam->y_angle) + point->z
				* sin(-env->cam->y_angle);
			new_z = -point->x * sin(-env->cam->y_angle) + point->z
				* cos(-env->cam->y_angle);
			point->x = (int)new_x;
			point->z = (int)new_z;
			x++;
		}
		y++;
	}
}

void	rotate_up(t_env *env)
{
	int		x;
	int		y;
	t_point	*point;
	double	new_y;
	double	new_z;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			point = &env->map->matrix[y][x];
			new_y = point->y * cos(env->cam->x_angle) + point->z
				* sin(env->cam->x_angle);
			new_z = -point->y * sin(env->cam->x_angle) + point->z
				* cos(env->cam->x_angle);
			point->y = (int)new_y;
			point->z = (int)new_z;
			x++;
		}
		y++;
	}
}

void	rotate_down(t_env *env)
{
	int		x;
	int		y;
	t_point	*point;
	double	new_y;
	double	new_z;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			point = &env->map->matrix[y][x];
			new_y = point->y * cos(env->cam->x_angle) + point->z
				* sin(-env->cam->x_angle);
			new_z = -point->y * sin(-env->cam->x_angle) + point->z
				* cos(env->cam->x_angle);
			point->y = (int)new_y;
			point->z = (int)new_z;
			x++;
		}
		y++;
	}
}

void	rotate_reverse_z(t_env *env)
{
	int		x;
	int		y;
	t_point	*point;
	double	new_y;
	double	new_x;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			point = &env->map->matrix[y][x];
			new_x = point->y * cos(env->cam->z_angle) - point->y
				* sin(env->cam->z_angle);
			new_y = point->x * sin(env->cam->z_angle) + point->y
				* cos(env->cam->z_angle);
			point->x = (int)new_x;
			point->y = (int)new_y;
			x++;
		}
		y++;
	}
}

void	rotate_z(t_env *env)
{
	int		x;
	int		y;
	t_point	*point;
	double	new_y;
	double	new_x;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			point = &env->map->matrix[y][x];
			new_x = point->x * cos(env->cam->z_angle) + point->y
				* sin(env->cam->z_angle);
			new_y = -point->x * sin(env->cam->z_angle) + point->y
				* cos(env->cam->z_angle);
			point->x = (int)new_x;
			point->y = (int)new_y;
			x++;
		}
		y++;
	}
}
