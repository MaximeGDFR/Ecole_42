/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:55:14 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/09 23:50:53 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	modify_color(int color, char component, int new_value)
{
	int	red;
	int	green;
	int	blue;
	int	transparency;

	transparency = (color >> 24) & 0xFF;
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = (color) & 0xFF;
	if (component == 'T')
		transparency = new_value;
	else if (component == 'R')
		red = new_value;
	else if (component == 'G')
		green = new_value;
	else if (component == 'B')
		blue = new_value;
	return ((transparency << 24) | (red << 16) | (green << 8) | blue);
}

int	inverted_color(int color)
{
	int	red;
	int	green;
	int	blue;
	int	transparency;

	transparency = 255 - ((color >> 24) & 0xFF);
	red = 255 - ((color >> 16) & 0xFF);
	green = 255 - ((color >> 8) & 0xFF);
	blue = 255 - ((color) & 0xFF);
	return ((transparency << 24) | (red << 16) | (green << 8) | blue);
}

int	calculate_color(int z, t_map *map)
{
	int		min_z;
	int		max_z;
	int		start_color;
	int		end_color;
	double	percentage;

	min_z = map->z_min;
	max_z = map->z_max;
	start_color = 0x0000FF;
	end_color = 0xFF0000;
	if (min_z == max_z)
		return (end_color);
	percentage = (double)(z - min_z) / (max_z - min_z);
	return (interpolate_color(start_color, end_color, percentage));
}

int	interpolate_color(int start, int end, double percentage)
{
	int	red;
	int	green;
	int	blue;
	int	transparency;

	transparency = (int)(((end >> 24) & 0xFF) * percentage
			+ ((start >> 24) & 0xFF) * (1 - percentage));
	red = (int)(((end >> 16) & 0xFF) * percentage
			+ ((start >> 16) & 0xFF) * (1 - percentage));
	green = (int)(((end >> 8) & 0xFF) * percentage
			+ ((start >> 8) & 0xFF) * (1 - percentage));
	blue = (int)((end & 0xFF) * percentage
			+ (start & 0xFF) * (1 - percentage));
	return ((transparency << 24) | (red << 16) | (green << 8) | blue);
}

void apply_single_color_to_drawing(t_data *data)
{
    int x;
    int y;

    // Appliquer une couleur unique à tous les points de la carte
    for (y = 0; y < data->map->height; y++)
    {
        for (x = 0; x < data->map->width; x++)
        {
            data->map->points[y][x].color = data->colors->color_1;
        }
    }

    // Redessiner la carte si nécessaire
    redraw_map(data, data->menu_opened);
}

void change_colors(t_data *data, int keycode)
{
    if (keycode == 'C')
    {
        data->colors->cycle++;

        if (data->colors->cycle > 6)
        {
            data->colors->cycle = 0;
        }

        // Associer le cycle à une couleur prédéfinie
        if (data->colors->cycle == 0)
        {
            data->colors->color_1 = RED;
            data->colors->color_2 = RED;
        }
        else if (data->colors->cycle == 1)
        {
            data->colors->color_1 = ORANGE;
            data->colors->color_2 = ORANGE;
        }
        else if (data->colors->cycle == 2)
        {
            data->colors->color_1 = YELLOW;
            data->colors->color_2 = YELLOW;
        }
        else if (data->colors->cycle == 3)
        {
            data->colors->color_1 = GREEN;
            data->colors->color_2 = GREEN;
        }
        else if (data->colors->cycle == 4)
        {
            data->colors->color_1 = BLUE;
            data->colors->color_2 = BLUE;
        }
        else if (data->colors->cycle == 5)
        {
            data->colors->color_1 = INDIGO;
            data->colors->color_2 = INDIGO;
        }
        else if (data->colors->cycle == 6)
        {
            data->colors->color_1 = VIOLET;
            data->colors->color_2 = VIOLET;
        }

        apply_single_color_to_drawing(data);
    }
}

void change_gradients(t_data *data, int keycode)
{
    if (keycode == 'G')
    {
        data->colors->use_gradient++;

        if (data->colors->use_gradient > 3)
        {
            data->colors->use_gradient = 0;
        }

        // Appliquer un dégradé en fonction du type choisi
        if (data->colors->use_gradient == 0)
        {
            data->colors->color_1 = SUNSET_START;
            data->colors->color_2 = SUNSET_END;
        }
        else if (data->colors->use_gradient == 1)
        {
            data->colors->color_1 = OCEAN_START;
            data->colors->color_2 = OCEAN_END;
        }
        else if (data->colors->use_gradient == 2)
        {
            data->colors->color_1 = FOREST_START;
            data->colors->color_2 = FOREST_END;
        }
        else if (data->colors->use_gradient == 3)
        {
            data->colors->color_1 = FIRE_START;
            data->colors->color_2 = FIRE_END;
        }

        apply_single_color_to_drawing(data);
    }
}
