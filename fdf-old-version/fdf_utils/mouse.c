/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:01:26 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/04 14:45:41 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	mouse_press(int button, int x, int y, void *param)
{
	t_data	*data = (t_data *)param;

	if (button == 1)
	{
		data->mouse.mouse_pressed = 1;
		data->mouse.last_x = x;
		data->mouse.last_y = y;
	}
	return (0);
}

int	mouse_mouve(int x, int y, void *param)
{
	t_data	*data = (t_data *)param;
	int		dx;
	int		dy;

	if (data->mouse.mouse_pressed)
	{
		dx = x - data->mouse.last_x;
		dy = y - data->mouse.last_y;
		(void)dx;
		(void)dy;
		mlx_clear_window(data->window.mlx, data->window.win);
		data->mouse.last_x = x;
		data->mouse.last_y = y;
	}
	return (0);
}

int	mouse_released(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	t_data	*data = (t_data *)param;

	if (button == 1)
		data->mouse.mouse_pressed = 0;
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}*/
