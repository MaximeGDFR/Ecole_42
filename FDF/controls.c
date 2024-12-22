/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:34:16 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/22 17:23:06 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_zoom(int keycode, t_env *env)
{
	if (keycode == MINUS || keycode == M)
		env->cam->zoom -= 2;
	else if (keycode == PLUS || keycode == P)
		env->cam->zoom += 2;
	draw_map(env);
}

void	handle_moves(int keycode, t_env *env)
{
	if (keycode == UP)
		env->cam->y_offset -= 10;
	else if (keycode == DOWN)
		env->cam->y_offset += 10;
	else if (keycode == LEFT)
		env->cam->x_offset -= 10;
	else if (keycode == RIGHT)
		env->cam->x_offset += 10;
	env->map->centered = 0;
	draw_map(env);
}

void	handle_rotations(int keycode, t_env *env)
{
	if (keycode == UP && env->ctrl_pressed)
		rotate_up(env);
	else if (keycode == DOWN && env->ctrl_pressed)
		rotate_down(env);
	else if (keycode == LEFT && env->ctrl_pressed)
		rotate_left(env);
	else if (keycode == RIGHT && env->ctrl_pressed)
		rotate_right(env);
	else if (keycode == Z && env->ctrl_pressed)
		rotate_reverse_z(env);
	else if (keycode == Z)
		rotate_z(env);
}

int	key_release(int keycode, t_env *env)
{
	if (keycode == CTRL)
		env->ctrl_pressed = 0;
	return (0);
}

void	handle_colors(int keycode, t_env *env, t_point *point)
{
	if (keycode == C)
	{
		env->map->color_mode++;
		apply_color_mode(env, point);
		update_colors(env);
	}
}

void	handle_views(int keycode, t_env *env)
{
	if (keycode == SPACE)
	{
		env->map->current_view++;
		if (env->map->current_view > 7)
			env->map->current_view = 1;
		env->map->centered = 1;
		draw_map(env);
		env->map->centered = 0;
	}
}

int	keyboards_controls(int key, t_env *env, t_point *point)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		handle_moves(key, env);
	else if (key == PLUS || key == MINUS || key == P || key == M)
		handle_zoom(key, env);
	else if (key == C)
		handle_colors(key, env, point);
	else if (key == SPACE)
		handle_views(key, env);
	else if (key == BACKSPACE)
		reset(env);
	else if (key == CTRL)
		env->ctrl_pressed = 1;
	if (env->ctrl_pressed && (key == UP || key == DOWN
			|| key == LEFT || key == RIGHT || key == Z))
		handle_rotations(key, env);
	else if (key == ESC)
		quit_program(env);
	return (0);
}
