/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:59:51 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 15:58:29 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_scale(t_map *map)
{
	int	max_map_size;
	int	window_size;

	if (map->width > map->height)
		max_map_size = map->width;
	else
		max_map_size = map->height;

	if (WIDTH < HEIGHT)
		window_size = WIDTH;
	else
		window_size = HEIGHT;

	map->tile_size = (window_size - 200) / max_map_size;
	if (map->tile_size < 1)
		map->tile_size = 1;
}

void	calculate_projected_bounds(t_map *map, int *x_min, int *x_max, int *y_min, int *y_max)
{
    int x, y;
    t_point projected_point;

    *x_min = INT_MAX;
    *x_max = INT_MIN;
    *y_min = INT_MAX;
    *y_max = INT_MIN;

    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            projected_point = map->points[y][x];
            apply_projection(&projected_point, map);
            if (projected_point.x < *x_min)
                *x_min = projected_point.x;
            if (projected_point.x > *x_max)
                *x_max = projected_point.x;
            if (projected_point.y < *y_min)
                *y_min = projected_point.y;
            if (projected_point.y > *y_max)
                *y_max = projected_point.y;
        }
    }
}

void	geometric_center(t_map *map)
{
	int		total_x;
	int		total_y;
	t_point	projected_point;
	int		x;
	int		y;

	total_x = 0;
	total_y = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			projected_point = map->points[y][x];
			apply_projection(&projected_point, map);
			total_x += projected_point.x;
			total_y += projected_point.y;
			x++;
		}
		y++;
	}
	map->geometric_center.x = total_x / (map->width * map->height);
	map->geometric_center.y = total_y / (map->width * map->height);
}
