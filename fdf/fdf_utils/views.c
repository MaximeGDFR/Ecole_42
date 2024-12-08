/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:33:47 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 17:15:25 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_view(t_map *map)
{

	if (map->current_view == 1)
		map->current_view = FRONT_VIEW;
	else if (map->current_view == 2)
		map->current_view = BACK_VIEW;
	else if (map->current_view == 3)
		map->current_view = TOP_VIEW;
	else if (map->current_view == 4)
		map->current_view = UNDER_VIEW;
	else if (map->current_view == 5)
		map->current_view = RIGHT_VIEW;
	else if (map->current_view == 6)
		map->current_view = LEFT_VIEW;
	else if (map->current_view == 7)
		map->current_view = ISO_VIEW;
	else if (map->current_view == 8)
		map->current_view = PERSPECTIVE_VIEW;
	else if (map->current_view == 9)
		map->current_view = OBLIQUE_VIEW;
	else if (map->current_view == 10)
		map->current_view = DIMETRIC_VIEW;
	else if (map->current_view == 11)
		map->current_view = TRIMETRIC_VIEW;
}

void	change_projection(t_point *point, t_map *map)
{
    if (map->current_view < 1 || map->current_view > 11)
    {
        printf("Error: Invalid current_view value: %d\n", map->current_view);
        map->current_view = 1; // Reset to default
    }
	if (map->current_view == 1)
		project_front(point, map);
	else if (map->current_view == 2)
		projection_back(point, map);
	else if (map->current_view == 3)
		projection_top(point, map);
	else if (map->current_view == 4)
		projection_under(point, map);
	else if (map->current_view == 5)
		project_right(point, map);
	else if (map->current_view == 6)
		project_left(point, map);
	else if (map->current_view == 7)
		projection_iso(point, map);
	else if (map->current_view == 8)
		projection_perspective(point, 1000);
	else if (map->current_view == 9)
		projection_oblique(point, 30.0, OBLIQUE_REDUCTION);
	else if (map->current_view == 10)
		projection_dimetric(point);
	else if (map->current_view == 11)
		projection_trimetric(point, 30.0, 45.0, 60.0);
}


void redraw_map(t_data *data, int menu_opened)
{
    mlx_clear_window(data->mlx, data->win);
    if (menu_opened == 1)
    {
        menu_background(data->mlx, data->win);
        open_menu(data->mlx, data->win, data->menu);
    }
    apply_projection(data->map);
    center_map(data->map);
    apply_center(data->map);
    draw_map(data, data->map);
}

void apply_projection(t_map *map)
{
    int y, x;
    
    map->x_min = map->x_max = 0;
    map->y_min = map->y_max = 0;

    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            // Sauvegarder la valeur z originale
            int original_z = map->points[y][x].z;

            // Réinitialiser à la position de base
            map->points[y][x].x = x * map->tile_size;
            map->points[y][x].y = y * map->tile_size;
            map->points[y][x].z = original_z; // Utiliser la valeur z originale

            // Appliquer la projection
            change_projection(&map->points[y][x], map);

            // Restaurer la valeur z originale après la projection
            map->points[y][x].z = original_z;

            // Mettre à jour les limites
            if (map->points[y][x].x < map->x_min) map->x_min = map->points[y][x].x;
            if (map->points[y][x].x > map->x_max) map->x_max = map->points[y][x].x;
            if (map->points[y][x].y < map->y_min) map->y_min = map->points[y][x].y;
            if (map->points[y][x].y > map->y_max) map->y_max = map->points[y][x].y;
        }
    }
}




void print_bounds(t_map *map)
{
    int x, y;
    int x_min, x_max, y_min, y_max;

    // Initialiser les valeurs des bornes avec les premières coordonnées
    x_min = map->points[0][0].x;
    x_max = map->points[0][0].x;
    y_min = map->points[0][0].y;
    y_max = map->points[0][0].y;

    // Parcourir la carte pour déterminer les bornes des coordonnées
    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            // Mettre à jour les bornes min et max pour x
            if (map->points[y][x].x < x_min)
                x_min = map->points[y][x].x;
            if (map->points[y][x].x > x_max)
                x_max = map->points[y][x].x;

            // Mettre à jour les bornes min et max pour y
            if (map->points[y][x].y < y_min)
                y_min = map->points[y][x].y;
            if (map->points[y][x].y > y_max)
                y_max = map->points[y][x].y;
        }
    }

    // Afficher les bornes
    printf("x_min: %d, x_max: %d, y_min: %d, y_max: %d\n", x_min, x_max, y_min, y_max);
}
