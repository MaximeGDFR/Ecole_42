/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:02:00 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 18:28:27 by maximegdfr       ###   ########.fr       */
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
		redraw_map(data, data->menu_opened);
	}
	if (keycode == P_KEY)
	{
		data->map->scale *= 1.5;
		redraw_map(data, data->menu_opened);
	}
	if (keycode == M_KEY)
	{
		data->map->scale *= 0.5;
		redraw_map(data, data->menu_opened);
	}
	else if (keycode == H_KEY)
	{
		if (data->menu_opened == 0)
		{
			data->menu_opened = 1;
			menu_background(data->mlx, data->win);
			open_menu(data->mlx, data->win, data->menu);
		}
		else
		{
			data->menu_opened = 0;
			mlx_clear_window(data->mlx, data->win);
			draw_map(data, data->map);
		}
	}
	if (keycode == UP)
	{
		data->map->y_offset -= 5;
		redraw_map(data, data->menu_opened);
	}
	if (keycode == DOWN)
	{
		data->map->y_offset += 5;
		redraw_map(data, data->menu_opened);
	}
	if (keycode == LEFT)
	{
		data->map->x_offset -= 5;
		redraw_map(data, data->menu_opened);
	}
	if (keycode == RIGHT)
	{
		data->map->x_offset += 5;
		redraw_map(data, data->menu_opened);
	}
	if (keycode == ENTER)
	{
		center_map(data->map);
		redraw_map(data, data->menu_opened);
	}
	if (keycode == BACKSPACE)
	{
		reset_map(data, data->menu_opened);
	}
	if (keycode == C_KEY)
    {
        change_colors(data, keycode);
    }
    if (keycode == G_KEY)
    {
        change_gradients(data, keycode);
    }
	return (0);
}
