/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_views.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:26:42 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 15:10:03 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_iso(t_point *point, t_map *map)
{
	int	prev_x;

	if (point == NULL || map == NULL)
		handle_error("Error: point or map is NULL in project_iso.\n", 1);
	prev_x = point->x;
	point->x = (point->x - point->y) * cos(0.523599);
	point->y = (prev_x + point->y) * sin(0.523599) - point->z;
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

void	projection_dimetric(t_point *point)
{
	float	cos45;
	float	sin45;
	float	cos30;
	float	sin30;
	int		tmp_x;

	cos45 = cos(M_PI / 4);
	sin45 = sin(M_PI / 4);
	cos30 = cos(M_PI / 6);
	sin30 = sin(M_PI / 6);
	tmp_x = point->x;
	point->x = tmp_x * cos45 - point->y * cos30;
	point->y = tmp_x * sin45 + point->y * sin30 - point->z;
}

void	projection_trimetric(t_point *point, float alpha, float beta,
	float gamma)
{
	float	rad_alpha;
	float	rad_beta;
	float	rad_gamma;
	int		new_x;
	int		new_y;

	rad_alpha = alpha * M_PI / 180.0;
	rad_beta = beta * M_PI / 180.0;
	rad_gamma = gamma * M_PI / 180.0;
	new_x = point->x * cos(rad_alpha) - point->y * cos(rad_beta);
	new_y = point->x * sin(rad_alpha) + point->y * sin(rad_beta)
		- point->z * cos(rad_gamma);
	point->x = new_x;
	point->y = new_y;
}
