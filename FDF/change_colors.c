/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:47:43 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/18 17:24:04 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	apply_color_mode(t_map *map)
{
	if (map->color_mode < 1 || map->color_mode > 12)
		map->color_mode = 1;
	if (map->color_mode >= 1 && map->color_mode <= 8)
		apply_uni_color(map);
	else if (map->color_mode >= 9 && map->color_mode <= 12)
		apply_specific_color(map);
}

void	apply_uni_color(t_env *env)
{
	if (env->map->color_mode == 1)
		env->points->color = WHITE;
	else if (env->map->color_mode == 2)
		env->points->color = RED;
	else if (env->map->color_mode == 3)
		env->points->color = ORANGE;
	else if (env->map->color_mode == 4)
		env->points->color = YELLOW;
	else if (env->map->color_mode == 5)
		env->points->color = GREEN;
	else if (env->map->color_mode == 6)
		env->points->color = BLUE;
	else if (env->map->color_mode == 7)
		env->points->color = INDIGO;
	else if (env->map->color_mode == 8)
		env->points->color = PURPLE;
}

void	apply_specific_color(t_env *env)
{
	if (env->map->color_mode == 9)
		earth_mode_color(env);
	else if (env->map->color_mode == 10)
		point->color = neon_mode_color();
	else if (env->map->color_mode == 11)
		point->color = jinx_mode_color();
	else if (env->map->color_mode == 12)
		point->color = charizard_color_mode();
	draw_map(env);
	draw_menu(env);
}

void	update_colors(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			apply_color_mode(&map->matrix[y][x]);
			x++;
		}
		y++;
	}
}
*/