/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:02:00 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/10 00:33:56 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_bonus(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == H_KEY)
	{
		data->menu_opened = !data->menu_opened;
		redraw_map(data, data->menu_opened);
	}
	if (keycode == C_KEY)
		change_colors(data, keycode);
	else if (keycode == G_KEY)
		change_gradients(data, keycode);
	return (0);
}

int	handle_moves(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == UP)
	{
		data->map->y_offset -= 5;
		redraw_map(data, data->menu_opened);
	}
	else if (keycode == DOWN)
	{
		data->map->y_offset += 5;
		redraw_map(data, data->menu_opened);
	}
	else if (keycode == LEFT)
	{
		data->map->x_offset -= 5;
		redraw_map(data, data->menu_opened);
	}
	else if (keycode == RIGHT)
	{
		data->map->x_offset += 5;
		redraw_map(data, data->menu_opened);
	}
	return (0);
}

int	handle_map(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC)
		close_window(data);
	else if (keycode == SPACE)
	{
		data->map->current_view = (data->map->current_view % 11) + 1;
		change_view(data->map);
		change_map(data, data->menu_opened);
	}
	if (keycode == ENTER)
	{
		data->map->x_offset = 0;
		data->map->y_offset = 0;
		center_map(data->map);
		redraw_map(data, data->menu_opened);
	}
	else if (keycode == BACKSPACE)
		reset_map(data, data->menu_opened);
	return (0);
}

int	handle_scale(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == P_KEY)
	{
		data->map->scale *= 1.1;
		redraw_map(data, data->menu_opened);
	}
	else if (keycode == M_KEY)
	{
		if (data->map->scale > 0.1)
		{
			data->map->scale /= 1.1;
			redraw_map(data, data->menu_opened);
		}
	}
	return (0);
}

int	handle_controls(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	printf("Keycode pressed: %d\n", keycode);
	handle_bonus(keycode, data);
	handle_moves(keycode, data);
	handle_map(keycode, data);
	handle_scale(keycode, data);
	return (0);
}
