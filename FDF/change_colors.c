/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:47:43 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/12 19:58:42 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_color_mode(t_point *point, t_env *env)
{
	if (env->map->color_mode < 1 || env->map->color_mode > 12)
		env->map->color_mode = 1;
	if (env->map->color_mode >= 1 && env->map->color_mode <= 8)
		apply_uni_color(point, env);
	else if (env->map->color_mode >= 9 && env->map->color_mode <= 12)
		apply_specific_color(point, env);
}

void	apply_uni_color(t_point *point, t_env *env)
{
	if (env->map->color_mode == 1)
		point->color = WHITE;
	else if (env->map->color_mode == 2)
		point->color = RED;
	else if (env->map->color_mode == 3)
		point->color = ORANGE;
	else if (env->map->color_mode == 4)
		point->color = YELLOW;
	else if (env->map->color_mode == 5)
		point->color = GREEN;
	else if (env->map->color_mode == 6)
		point->color = BLUE;
	else if (env->map->color_mode == 7)
		point->color = INDIGO;
	else if (env->map->color_mode == 8)
		point->color = PURPLE;
}

void	apply_specific_color(t_point *point, t_env *env)
{
	if (env->map->color_mode == 9)
		earth_mode_color(point, env);
/*	else if (env->map->color_mode == 10)
		point->color = neon_mode_color();
	else if (env->map->color_mode == 11)
		point->color = jinx_mode_color();
	else if (env->map->color_mode == 12)
		point->color = charizard_color_mode();*/
}
