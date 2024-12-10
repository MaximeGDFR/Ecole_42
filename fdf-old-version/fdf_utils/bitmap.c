/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:22:44 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/10 15:45:16 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_bitmap(t_data *data, int width, int height)
{
	data->bitmap.width = width;
	data->bitmap.height = height;
	data->bitmap.img = mlx_new_image(data->mlx, width, height);
	if (!data->bitmap.img)
		handle_error("Failed to create bitmap image.\n", 1);
	data->bitmap.addr = mlx_get_data_addr(data->bitmap.img, &data->bitmap.bpp,
			&data->bitmap.size_line, &data->bitmap.endian);
}

void	draw_pixel(t_bitmap *bitmap, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < bitmap->width && y >= 0 && y < bitmap->height)
	{
		dest = bitmap->addr + (y * bitmap->size_line + x * (bitmap->bpp / 8));
		*(unsigned int *)dest = color;
	}
}

void	draw_line_bresenham(t_data *data, t_point p1, t_point p2)
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
		{
			draw_pixel(&data->bitmap, p1.x, p1.y, 0xFFFFFF);
		}
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_coordinates(&bresenham, &p1.x, &p1.y);
	}
}

void	draw_line_bitmap(t_data *data, t_map *map, int x, int y)
{
	t_point	p1;
	t_point	p2;

	if (x + 1 < map->width)
	{
		p1 = map->points[y][x];
		p2 = map->points[y][x + 1];
		draw_line_bresenham(data, p1, p2);
	}
	if (y + 1 < map->height)
	{
		p1 = map->points[y][x];
		p2 = map->points[y + 1][x];
		draw_line_bresenham(data, p1, p2);
	}
}

void	draw_map(t_data *data, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_line_bitmap(data, map, x, y);
			x++;
		}
		y++;
	}
}