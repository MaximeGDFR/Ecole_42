/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:47:43 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/21 18:56:14 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_color_mode(t_env *env, t_point *point)
{
	if (env->map->color_mode < 1 || env->map->color_mode > 12)
		env->map->color_mode = 1;
	if (env->map->color_mode >= 1 && env->map->color_mode <= 8)
		apply_uni_color(env, point);
	else if (env->map->color_mode >= 9 && env->map->color_mode <= 12)
		apply_specific_color(env, point);
}

void	apply_uni_color(t_env *env, t_point *point)
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
		point->color = PURPLE;
	else if (env->map->color_mode == 8)
		point->color = GREY;
}

void	apply_specific_color(t_env *env, t_point *point)
{
	if (env->map->color_mode == 9)
		earth_mode_color(env, point);
	else if (env->map->color_mode == 10)
		neon_mode_color(env, point);
	else if (env->map->color_mode == 11)
		jinx_mode_color(env, point);
	else if (env->map->color_mode == 12)
		charizard_mode_color(env, point);
}

void	update_colors(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			apply_color_mode(env, &env->map->matrix[y][x]);
			x++;
		}
		y++;
	}
	draw_map(env);
}
