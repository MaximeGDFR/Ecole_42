/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:40:09 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/17 23:38:12 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_isometric(t_point *point, t_env *env)
{
	int	prev_x;

	calculate_depth(env);
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_iso.\n", 1);
	prev_x = point->x;
	point->x = (point->x - point->y) * cos(0.523599);
	point->y = (prev_x + point->y) * sin(0.523599) - (point->z * env->map->depth
			* env->cam->z_height);
	point->x *= env->cam->zoom;
	point->y *= env->cam->zoom;
	point->x += env->cam->x_offset;
	point->y += env->cam->y_offset;
}

void	projection_perspective(t_env *env, t_point *point, float d)
{
	calculate_depth(env);
	if (d + (point->z * env->map->depth) != 0)
	{
		point->x = point->x / (1 + (point->z * env->map->depth) / d);
		point->y = point->y / (1 + (point->z * env->map->depth) / d);
	}
	point->x *= env->cam->z_height;
	point->y *= env->cam->z_height;
	point->x *= env->cam->zoom;
	point->y *= env->cam->zoom;
	point->x += env->cam->x_offset;
	point->y += env->cam->y_offset;
}

void	projection_oblique(t_env *env, t_point *point, float angle, float reduction)
{
	float	rad;

	calculate_depth(env);
	rad = angle * M_PI / 180.0;
	point->x = point->x + reduction * point->z * cos(rad) * env->map->depth
		* env->cam->z_height;
	point->y = point->y + reduction * point->z * sin(rad) * env->map->depth
		* env->cam->z_height;
	point->x *= env->cam->zoom;
	point->y *= env->cam->zoom;
	point->x += env->cam->x_offset;
	point->y += env->cam->y_offset;
}
