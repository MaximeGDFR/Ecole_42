/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:37:59 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/17 23:41:29 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_front(t_point *point, t_env *env)
{
	calculate_depth(env);
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_front.\n", 1);
	point->y -= point->z * env->map->depth;
	point->x *= env->cam->zoom;
	point->y *= env->cam->zoom;
	point->x += env->cam->x_offset;
	point->y += env->cam->y_offset;
}

void	projection_top(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_top.\n", 1);
	calculate_depth(env);
	point->x *= env->cam->zoom;
	point->y *= env->cam->zoom;
	point->x += env->cam->x_offset;
	point->y += env->cam->y_offset;
}

void	projection_right(t_point *point, t_env *env)
{
	int	tmp;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_right.\n", 1);
	calculate_depth(env);
	tmp = point->x;
	point->x = point->z * env->map->depth;
	point->z = tmp * env->map->depth;
	point->x *= env->cam->zoom;
	point->y *= env->cam->zoom;
	point->x += env->cam->x_offset;
	point->y += env->cam->y_offset;
}

void	projection_left(t_point *point, t_env *env)
{
	int	tmp;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_left.\n", 1);
	calculate_depth(env);
	tmp = env->map->width - (point->z * env->map->depth);
	point->x = tmp;
	point->z = tmp;
	point->x *= env->cam->zoom;
	point->y *= env->cam->zoom;
	point->x += env->cam->x_offset;
	point->y += env->cam->y_offset;
}
