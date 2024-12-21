/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:55:24 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/21 15:16:13 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	display_projection_infos(t_env *env, int *current_line)
{
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE,
		"PROJECTION INFORMATIONS");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "View :");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "Color_mode : ");
	(*current_line)++;
	(*current_line) += 1;
	return (*current_line);
}

void	display_map_infos(t_env *env, int *current_line)
{
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "MAP INFORMATIONS");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "Size :");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "x_max :");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "y_max : ");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "z_max : ");
	(*current_line)++;
	(*current_line) += 1;
}

void	display_fdf_keyboards(t_env *env, int *current_line)
{
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "FDF KEYBOARDS");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE,
		"Arrows : Move x/y axis");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "+/- : Zoom in/out");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "C : Change color mode");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "Space : Change view");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "Backspace : Reset");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "Esc : Quit program");
	(*current_line)++;
	(*current_line) += 1;
}

void	display_fdf_mouse(t_env *env, int *current_line)
{
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "FDF MOUSE");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "Scroll : Zoom in/out");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE,
		"Left : Rotate x/y axis");
	(*current_line)++;
	mlx_string_put(env->menu->mlx, env->menu->win, env->menu->x_left,
		get_position(env->menu, *current_line), WHITE, "Right : Move x/y axis");
	(*current_line)++;
}
