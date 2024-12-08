/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiaze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:54:26 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 14:35:32 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



t_colors	*init_colors(void)
{
	t_colors	*colors;

	colors = malloc(sizeof(t_colors));
	if (!colors)
		handle_error("Allocation error.\n", 1);
	colors->color_1 = 0xFFFFFF;
	colors->color_2 = 0x0000FF;
	colors->cycle = 0;
	colors->use_gradient = 1;
	return (colors);
}

t_menu	*init_menu(void)
{
	t_menu	*menu;

	menu = malloc(sizeof(t_menu));
	if (!menu)
		handle_error("Allocation error.\n", 1);

	menu->title = "FDF COMMANDS";
	menu->command_b = "UP : Move up";
	menu->command_c = "DOWN : Move down";
	menu->command_d = "LEFT : Move left";
	menu->command_e = "RIGHT : Move right";
	menu->command_f = "P : Zoom in";
	menu->command_g = "M : Zoom out";
	menu->command_h = NULL;
	return (menu);
}

/*t_map	*init_map(char *filename)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		handle_error("Allocation error.\n", 1);
	map->height = get_height(filename);
	map->width = get_width(filename);
	init_map_values(map);
	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		handle_error("Allocation error.\n", 1);
	i = 0;
	while (i < map->height)
	{
		map->points[i] = malloc(sizeof(t_point) * map->width);
		if (!map->points[i])
			handle_error("Allocation error.\n", 1);
		i++;
	}
	fill_matrix(filename, map);
	calculate_scale(map);
	return (map);
}*/
