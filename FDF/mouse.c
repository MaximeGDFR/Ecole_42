/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:54:51 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/16 21:58:20 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_down(int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (env->mouse->button == MOUSE_WHEEL_UP
		|| env->mouse->button == MOUSE_WHEEL_DOWN)
		mouse_zoom(env);
	else if (env->mouse->button == MOUSE_CLICK_LEFT
		|| env->mouse->button == MOUSE_CLICK_RIGHT)
	{
		env->mouse->button = 1;
		env->mouse->prev_x = x;
		env->mouse->prev_y = y;
	}
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return (0);
	if (env->mouse->button == MOUSE_CLICK_LEFT)
	{
		env->cam->x_offset += (x - env->mouse->prev_x);
		env->cam->y_offset += (y - env->mouse->prev_y);
		env->mouse->prev_x = x;
		env->mouse->prev_y = y;
		draw_map(env);
	}
	if (env->mouse->button == MOUSE_CLICK_RIGHT)
	{
		env->cam->x_angle += (y - env->mouse->prev_y) * 0.002;
		env->cam->y_angle += (x - env->mouse->prev_x) * 0.002;
		env->mouse->prev_x = x;
		env->mouse->prev_y = y;
		draw_map(env);
	}
	return (0);
}

int	mouse_up(int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	(void)x;
	(void)y;
	if (env->mouse->button == MOUSE_WHEEL_UP
		|| env->mouse->button == MOUSE_WHEEL_DOWN)
		mouse_zoom(env);
	else if (env->mouse->button == MOUSE_CLICK_LEFT
		|| env->mouse->button == MOUSE_CLICK_RIGHT)
		env->mouse->button = 0;
	return (0);
}

void	mouse_zoom(t_env *env)
{
	if (env->mouse->button == MOUSE_WHEEL_UP)
		env->cam->zoom += 2;
	if (env->mouse->button == MOUSE_WHEEL_DOWN)
		env->cam->zoom -= 2;
	draw_map(env);
}

int	handle_mouse(t_env *env)
{
	mlx_hook(env->win, 4, 0, mouse_down, env);
	mlx_hook(env->win, 5, 0, mouse_move, env);
	mlx_hook(env->win, 6, 0, mouse_up, env);
	return (0);
}
