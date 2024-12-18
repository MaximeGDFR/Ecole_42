/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_specifics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:51:58 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/18 17:23:25 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	earth_mode_color(t_env *env)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	if (z_delta <= 0)
		env->points->color = 0xFF;
	color_steps = z_delta / 5;
	if (env->points->z < env->map->z_min + color_steps)
		env->points->color = 0x000080;
	else if (env->points->z < env->map->z_min + (color_steps * 2))
		env->points->color = 0x4169E1;
	else if (env->points->z < env->map->z_min + (color_steps * 3))
		env->points->color = 0x87CEEB;
	else if (env->points->z < env->map->z_min + (color_steps * 4))
		env->points->color = 0x228B22;
	else
		env->points->color = 0x90EE90;
}

void	neon_mode_color(t_env *env)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	if (z_delta <= 0)
		env->points->color = 0xFF;
	color_steps = z_delta / 5;
	if (env->points->z < env->map->z_min + color_steps)
		env->points->color = 0xEF44F2;
	else if (env->points->z < env->map->z_min + (color_steps * 2))
		env->points->color = 0x3E2EA6;
	else if (env->points->z < env->map->z_min + (color_steps * 3))
		env->points->color = 0x1D1A73;
	else if (env->points->z < env->map->z_min + (color_steps * 4))
		env->points->color = 0x4A88D9;
	else
		env->points->color = 0x72F2F2;
}

void	jinx_mode_color(t_env *env)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	if (z_delta <= 0)
		env->points->color = 0xFF;
	color_steps = z_delta / 5;
	if (env->points->z < env->map->z_min + color_steps)
		env->points->color = 0xF20789;
	else if (env->points->z < env->map->z_min + (color_steps * 2))
		env->points->color = 0xBF247A;
	else if (env->points->z < env->map->z_min + (color_steps * 3))
		env->points->color = 0x1B2459;
	else if (env->points->z < env->map->z_min + (color_steps * 4))
		env->points->color = 0x05F2DB;
	else
		env->points->color = 0xD9B8B8;
}

void	charizard_mode_color(t_env *env)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	if (z_delta <= 0)
		env->points->color = 0xFF;
	color_steps = z_delta / 5;
	if (env->points->z < env->map->z_min + color_steps)
		env->points->color = 0x000080;
	else if (env->points->z < env->map->z_min + (color_steps * 2))
		env->points->color = 0x4169E1;
	else if (env->points->z < env->map->z_min + (color_steps * 3))
		env->points->color = 0x87CEEB;
	else if (env->points->z < env->map->z_min + (color_steps * 4))
		env->points->color = 0x228B22;
	else
		env->points->color = 0x90EE90;
}