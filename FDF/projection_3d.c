/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:40:09 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/12 18:43:26 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_iso(t_point *point, t_env *env)
{
	int	prev_x;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_iso.\n", 1);
	prev_x = point->x;
	point->x = (point->x - point->y) * cos(M_PI / 6);
	point->y = (prev_x + point->y) * sin(M_PI / 6) - point->z;
}

void	projection_perspective(t_point *point, float d)
{
	if (d + point->z != 0)
	{
		point->x = point->x / (1 + point->z / d);
		point->y = point->y / (1 + point->z / d);
	}
}

void	projection_oblique(t_point *point, float angle, float reduction)
{
	float	rad;

	rad = angle * M_PI / 180.0;
	point->x = point->x + reduction * point->z * cos(rad);
	point->y = point->y + reduction * point->z * sin(rad);
}
