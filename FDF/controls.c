/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:34:16 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/18 17:36:42 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_env *env)
{
	env->map->centered = 1;
	env->cam->x_offset = 0;
	env->cam->y_offset = 0;
	if (env->cam->iso)
	{
		env->cam->x_angle = -0.615472907;
		env->cam->y_angle = -0.523599;
		env->cam->z_angle = 0.615472907;
	}
	env->cam->z_height = 1;
	env->cam->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
	draw_map(env);
	draw_menu(env);
}

void	handle_zoom(int keycode, t_env *env)
{
	if (keycode == MINUS_KEY || keycode == M_KEY)
		env->cam->zoom -= 2;
	else if (keycode == PLUS_KEY || keycode == P_KEY)
		env->cam->zoom += 2;
	draw_map(env);
	draw_menu(env);
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
	draw_menu(env);
}

int	keyboards_controls(int keycode, t_env *env)
{
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		handle_moves(keycode, env);
	else if (keycode == PLUS_KEY || keycode == MINUS_KEY || keycode == P_KEY
		|| keycode == M_KEY)
		handle_zoom(keycode, env);
	else if (keycode == ENTER)
		reset(env);
/*	else if (keycode == C_KEY)
	{
		printf("Keycode : %d\n", keycode);
		printf("Current color mode: %d\n", env->map->color_mode);
		env->map->color_mode++;
		apply_color_mode(env);
		draw_map(env);
		draw_menu(env);
	}*/
	else if (keycode == SPACE)
	{
		env->map->current_view++;
		if (env->map->current_view > 7)
			env->map->current_view = 1;
		env->map->centered = 1;
		draw_map(env);
		env->map->centered = 0;
	}
	else if (keycode == ESC)
		quit_program(env);
	draw_menu(env);
	return (0);
}
