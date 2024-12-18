/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:54:51 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/18 15:32:12 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_down(int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	printf("Mouse down: button %d at (%d, %d)\n", env->mouse->button, x, y);
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
	printf("Mouse moved to (%d, %d)\n", x, y);
	return (0);
}

int	mouse_up(int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	(void)x;
	(void)y;
	printf("Mouse up: button %d at (%d, %d)\n", env->mouse->button, x, y);
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
