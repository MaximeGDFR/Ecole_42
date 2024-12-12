/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:54:51 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/12 14:06:11 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(t_mouse *mouse, t_point *point, int keycode)
{
	if (keycode == MOUSE_CLICK_LEFT)
	{
		mouse->button = 1;
		mouse->prev_x = point->x;
		mouse->prev_y = point->y;
	}
	return (0);
}

int	mouse_mouve(t_env *env, t_mouse *mouse, t_point *point, int keycode)
{

	int		dx;
	int		dy;

	if (mouse->button)
	{
		dx = point->x - mouse->prev_x;
		dy = point->y - mouse->prev_y;
		(void)dx;
		(void)dy;
		mlx_clear_window(env->mlx, env->win);
		mouse->prev_x = point->x;
		mouse->prev_y = point->y;
	}
	return (0);
}

int	mouse_released(t_mouse *mouse, int keycode)
{
	if (keycode != MOUSE_CLICK_LEFT || keycode != MOUSE_CLICK_RIGHT)
		mouse->button = 0;
	return (0);
}

