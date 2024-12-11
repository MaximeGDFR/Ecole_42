/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:51:04 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 14:57:53 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_front(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_front.\n", 1);
	point -> y -= (point -> z);
	clip_point(point);
}

void	projection_back(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_back.\n", 1);
	point->x = (env->width - 1 - point->x);
	point->y = point->y + point->z;
	clip_point(point);
}

void	projection_top(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_top.\n", 1);
	clip_point(point);
}

void	projection_under(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_under.\n", 1);
	point->y = env->height - point->y;
	clip_point(point);
}

void	project_right(t_point *point, t_env *env)
{
	int	tmp;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_right.\n", 1);
	tmp = point->x;
	point->x = point->z;
	point->z = tmp;
	clip_point(point);
}
