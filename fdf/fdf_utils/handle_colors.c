/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:55:14 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/04 16:15:49 by maximegdfr       ###   ########.fr       */
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