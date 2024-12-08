/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:37:13 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 17:08:54 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void center_map(t_map *map)
{
    double scale_x = (WIDTH * 0.8) / (map->x_max - map->x_min);
    double scale_y = (HEIGHT * 0.8) / (map->y_max - map->y_min);
    map->scale = fmin(scale_x, scale_y);

    map->x_center = (map->x_min + map->x_max) / 2.0;
    map->y_center = (map->y_min + map->y_max) / 2.0;

    map->x_center_offset = WIDTH / 2 - map->x_center * map->scale;
    map->y_center_offset = HEIGHT / 2 - map->y_center * map->scale;
}


void apply_center(t_map *map)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            map->points[y][x].x = (map->points[y][x].x - map->x_center) * map->scale + WIDTH / 2;
            map->points[y][x].y = (map->points[y][x].y - map->y_center) * map->scale + HEIGHT / 2;
        }
    }
}





void	reset_map(t_data *data)
{
	t_map	*map;

	map = data->map;
	calculate_scale(data->map);
	data->map->current_view = 1;
	center_map(map);
	apply_center(map);
	redraw_map(data, data->menu_opened);
}





void print_map_info(t_map *map)
{
    static int call_count = 0;  // Variable statique pour compter les appels
    call_count++;  // Incrémente à chaque appel de la fonction

    printf("Call #%d\n", call_count);  // Affiche le numéro d'appel
    printf("Map Information:\n");
	printf("Current view : %d\n", map->current_view);
    printf("Height: %d\n", map->height);
    printf("Width: %d\n", map->width);
    printf("Tile Size: %d\n", map->tile_size);
    printf("X Min: %d\n", map->x_min);
    printf("X Max: %d\n", map->x_max);
    printf("Y Min: %d\n", map->y_min);
    printf("Y Max: %d\n", map->y_max);
    printf("Drawing Width: %d\n", map->drawing_width);
    printf("Drawing Height: %d\n", map->drawing_height);
    printf("Z Min: %d\n", map->z_min);
    printf("Z Max: %d\n", map->z_max);
    printf("X Offset: %d\n", map->x_offset);
    printf("Y Offset: %d\n", map->y_offset);
    printf("X Center Offset: %d\n", map->x_center_offset);
    printf("Y Center Offset: %d\n", map->y_center_offset);
    printf("X Center: %.2f\n", map->x_center);
    printf("Y Center: %.2f\n", map->y_center);
    printf("Window Width Center: %.2f\n", map->window_width_center);
    printf("Window Height Center: %.2f\n", map->window_height_center);
}
