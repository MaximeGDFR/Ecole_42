/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:46:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 16:59:47 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_sign(int value)
{
	if (value < 0)
		return (-1);
	else
		return (1);
}

void	update_coordinates(t_bresenham *bresenham, int *x, int *y)
{
	int	err_2;

	err_2 = bresenham->err * 2;
	if (err_2 > -bresenham->dy)
	{
		bresenham->err -= bresenham->dy;
		*x += bresenham->sx;
	}
	if (err_2 < bresenham->dx)
	{
		bresenham->err += bresenham->dx;
		*y += bresenham->sy;
	}
}

void	draw_line_bresenham(t_data *data, t_point p1, t_point p2, int color)
{
	t_bresenham	bresenham;

	bresenham.dx = ft_abs(p2.x - p1.x);
	bresenham.dy = ft_abs(p2.y - p1.y);
	bresenham.sx = get_sign(p2.x - p1.x);
	bresenham.sy = get_sign(p2.y - p1.y);
	bresenham.err = bresenham.dx - bresenham.dy;
	while (1)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
			mlx_pixel_put(data->mlx, data->win, p1.x, p1.y, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_coordinates(&bresenham, &p1.x, &p1.y);
	}
}

void	center_map(t_map *map)
{
	int	center_x;
	int	center_y;

	geometric_center(map);
	center_x = map->geometric_center.x;
	center_y = map->geometric_center.y;
	map->x_offset = (WIDTH / 2) - center_x;
	map->y_offset = (HEIGHT / 2) - center_y;
}

void	reset_map(t_data *data)
{
	data->map->tile_size = 5;
	data->map->x_offset = WIDTH / 2;
	data->map->y_offset = HEIGHT / 2;
	data->map->current_view = 1;
	center_map(data->map);
	redraw_map(data);
}
