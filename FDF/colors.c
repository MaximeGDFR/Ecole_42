/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:19:10 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/12 11:33:07 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	earth_mode_color(t_point *point, t_env *env)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	color_steps = z_delta / 5;
	if (point->z < env->map->z_min + color_steps)
		point->color = 0x000080;
	else if (point->z < env->map->z_min + (color_steps * 2))
		point->color = 0x4169E1;
	else if (point->z < env->map->z_min + (color_steps * 3))
		point->color = 0x87CEEB;
	else if (point->z < env->map->z_min + (color_steps * 4))
		point->color = 0x228B22;
	else
		point->color = 0x90EE90;
}
