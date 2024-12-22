/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_specifics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:51:58 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/21 18:59:20 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	earth_mode_color(t_env *env, t_point *point)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	if (z_delta <= 0)
		point->color = 0xFF;
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

void	neon_mode_color(t_env *env, t_point *point)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	if (z_delta <= 0)
		point->color = 0xFF;
	color_steps = z_delta / 5;
	if (point->z < env->map->z_min + color_steps)
		point->color = 0xEF44F2;
	else if (point->z < env->map->z_min + (color_steps * 2))
		point->color = 0x3E2EA6;
	else if (point->z < env->map->z_min + (color_steps * 3))
		point->color = 0x1D1A73;
	else if (point->z < env->map->z_min + (color_steps * 4))
		point->color = 0x4A88D9;
	else
		point->color = 0x72F2F2;
}

void	jinx_mode_color(t_env *env, t_point *point)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	if (z_delta <= 0)
		point->color = 0xFF;
	color_steps = z_delta / 5;
	if (point->z < env->map->z_min + color_steps)
		point->color = 0xF20789;
	else if (point->z < env->map->z_min + (color_steps * 2))
		point->color = 0xBF247A;
	else if (point->z < env->map->z_min + (color_steps * 3))
		point->color = 0x1B2459;
	else if (point->z < env->map->z_min + (color_steps * 4))
		point->color = 0x05F2DB;
	else
		point->color = 0xD9B8B8;
}

void	charizard_mode_color(t_env *env, t_point *point)
{
	int		color_steps;
	int		z_delta;

	z_delta = env->map->z_max - env->map->z_min;
	if (z_delta <= 0)
		point->color = 0xFF;
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

// METTRE A JOUR LES COULEURS DU CHARIZARD MODE