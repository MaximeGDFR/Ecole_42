/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:25:21 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 16:44:13 by maximegdfr       ###   ########.fr       */
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
			mlx_pixel_put(data->mlx, data->win, p1.x, p1.y, 0xFFFFFF);
		}
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_coordinates(&bresenham, &p1.x, &p1.y);
	}
}

void draw_lines(t_data *data, t_map *map, int x, int y)
{
    t_point p1;
    t_point p2;

    // Horizontal line to the right
    if (x + 1 < map->width)
    {
        p1 = map->points[y][x];
        p2 = map->points[y][x + 1];
        draw_line_bresenham(data, p1, p2);
    }

    // Vertical line downwards
    if (y + 1 < map->height)
    {
        p1 = map->points[y][x];
        p2 = map->points[y + 1][x];
        draw_line_bresenham(data, p1, p2);
    }
}



void draw_map(t_data *data, t_map *map)
{
    printf("Drawing map...\n");
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (x == 0 && y == 0)
                printf("First point: (%d, %d)\n", map->points[y][x].x, map->points[y][x].y);
            if (x == map->width-1 && y == map->height-1)
                printf("Last point: (%d, %d)\n", map->points[y][x].x, map->points[y][x].y);
            draw_lines(data, map, x, y);
        }
    }
}
