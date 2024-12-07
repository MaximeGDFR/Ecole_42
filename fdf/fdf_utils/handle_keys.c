/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:02:00 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 15:43:03 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_controls(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC)
		close_window(data);
	if (keycode == SPACE)
	{
		data->map->current_view = (data->map->current_view % 11) + 1;
		change_view(data->map);
		redraw_map(data);
	}
	if (keycode == P_KEY)
	{
		data->map->tile_size += 1;
		redraw_map(data);
	}
	if (keycode == M_KEY)
	{
		data->map->tile_size -= 1;
		redraw_map(data);
	}
	if (keycode == UP)
	{
		data->map->y_offset -= 5;
		redraw_map(data);
	}
	if (keycode == DOWN)
	{
		data->map->y_offset += 5;
		redraw_map(data);
	}
	if (keycode == LEFT)
	{
		data->map->x_offset -= 5;
		redraw_map(data);
	}
	if (keycode == RIGHT)
	{
		data->map->x_offset += 5;
		redraw_map(data);
	}
	if (keycode == ENTER)
	{
		center_map(data->map);
		redraw_map(data);
	}
	if (keycode == BACKSPACE)
	{
		reset_map(data);
		redraw_map(data);
	}
	return (0);
}
