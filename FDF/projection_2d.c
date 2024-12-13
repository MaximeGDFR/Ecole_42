/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:37:59 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/12 18:44:09 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_front(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_front.\n", 1);
	point -> y -= (point -> z);
}

void	projection_top(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_top.\n", 1);
}

void	projection_right(t_point *point, t_env *env)
{
	int	tmp;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_right.\n", 1);
	tmp = point->x;
	point->x = point->z;
	point->z = tmp;
}

void	projection_left(t_point *point, t_env *env)
{
	int	tmp;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_left.\n", 1);
	tmp = env->map->width - (point -> z);
	point -> x = tmp;
	point -> z = tmp;
}
