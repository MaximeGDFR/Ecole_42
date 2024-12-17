/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_views.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:32:37 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 16:59:14 by maximegdfr       ###   ########.fr       */
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

void	apply_projection(t_point *point, t_map *map)
{
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

void	draw_lines(t_data *data, t_map *map, int x, int y)
{
	t_point	p1;
	t_point	p2;

	p1 = map->points[y][x];
	apply_projection(&p1, map);
	p1.x += map->x_offset;
	p1.y += map->y_offset;
	if (x < map->width - 1)
	{
		p2 = map->points[y][x + 1];
		apply_projection(&p2, map);
		p2.x += map->x_offset;
		p2.y += map->y_offset;
		draw_line_bresenham(data, p1, p2, p1.color);
	}
	if (y < map->height - 1)
	{
		p2 = map->points[y + 1][x];
		apply_projection(&p2, map);
		p2.x += map->x_offset;
		p2.y += map->y_offset;
		draw_line_bresenham(data, p1, p2, p1.color);
	}
}

void	draw_map(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{

			draw_lines(data, map, x, y);
			x++;
		}
		y++;
	}
}

void	redraw_map(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map(data, data->map);
}
