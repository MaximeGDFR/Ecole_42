/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:25:29 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/04 14:46:38 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	intermediate_color(int start, int end, double ratio)
{
	int	transparency;
	int	red;
	int	green;
	int	blue;

	transparency = (int)(get_component(start, 24) + (get_component(end, 24) - get_component(start, 24)) * ratio);
	red = (int)(get_component(start, 16) + (get_component(end, 16) - get_component(start, 16)) * ratio);
	green = (int)(get_component(start, 8) + (get_component(end, 8) - get_component(start, 8)) * ratio);
	blue = (int)(get_component(start, 0) + (get_component(end, 0) - get_component(start, 0)) * ratio);

	return (create_color(transparency, red, green, blue));
}

void	draw_horizontal_gradient(t_data *data, int x1, int x2, int y, int start_color, int end_color)
{
	int		x;
	double	ratio;
	int		color;

	x = x1;
	while (x <= x2)
	{
		ratio = (double)(x - x1) / (x2 - x1);
		color = intermediate_color(start_color, end_color, ratio);
		put_pixel(data, x, y, color);
		x++;
	}
}

void	draw_vertical_gradient(t_data *data, int x, int y1, int y2, int start_color, int end_color)
{
	int		y;
	double	ratio;
	int		color;

	y = y1;
	while (y <= y2)
	{
		ratio = (double)(y - y1) / (y2 - y1);
		color = intermediate_color(start_color, end_color, ratio);
		put_pixel(data, x, y, color);
		y++;
	}
}

void	draw_diagonal_gradient(t_data *data, int x1, int x2, int y1, int y2, int start_color, int end_color)
{
	int		x;
	int		y;
	double	ratio_x;
	double	ratio_y;
	int		color;

	x = x1;
	y = y1;
	while (y <= y2)
	{
		while (x <= x2)
		{
			ratio_x = (double)(x - x1) / (x2 - x1);
			ratio_y = (double)(y - y1) / (y2 - y1);
			color = intermediate_color(start_color, end_color, (ratio_x + ratio_y) / 2.0);
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}
*/