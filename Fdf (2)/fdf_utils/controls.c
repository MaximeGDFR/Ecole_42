/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:02:00 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 21:09:19 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	handle_bonus(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == C_KEY)
		change_colors(env, keycode);
	else if (keycode == G_KEY)
		change_gradients(env, keycode);
	return (0);
}*/

int	handle_moves(int keycode, t_env *env)
{
	if (keycode == UP)
	{
		env->y_offset -= 5;
		redraw_map(env);
	}
	else if (keycode == DOWN)
	{
		env->y_offset += 5;
		redraw_map(env);
	}
	else if (keycode == LEFT)
	{
		env->x_offset -= 5;
		redraw_map(env);
	}
	else if (keycode == RIGHT)
	{
		env->x_offset += 5;
		redraw_map(env);
	}
	return (0);
}

int	handle_map(int keycode, t_env *env)
{
	if (keycode == ESC)
		close_window(env);
	else if (keycode == SPACE)
	{
		env->current_view = (env->current_view % 11) + 1;
		change_view(env);
		change_map(env);
	}
	if (keycode == ENTER)
	{
		env->x_offset = 0;
		env->y_offset = 0;
		center_map(env);
		redraw_map(env);
	}
	else if (keycode == BACKSPACE)
		reset_map(env);
	return (0);
}

int	handle_scale(int keycode, t_env *env)
{
	if (keycode == P_KEY)
	{
		env->scale *= 1.1;
		redraw_map(env);
	}
	else if (keycode == M_KEY)
	{
		if (env->scale > 0.1)
		{
			env->scale /= 1.1;
			redraw_map(env);
		}
	}
	return (0);
}

int	key_controls(int keycode, t_env *env)
{
//	handle_bonus(keycode, env);
	handle_moves(keycode, env);
	handle_map(keycode, env);
	handle_scale(keycode, env);
	return (0);
}
