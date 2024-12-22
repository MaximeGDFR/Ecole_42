/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:21:31 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/22 15:44:15 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_env *env)
{
	int		current_line;

	current_line = 0;
	display_projection_infos(env, &current_line);
	display_map_infos(env, &current_line);
	display_fdf_keyboards(env, &current_line);
	mlx_put_image_to_window(env->menu->mlx, env->menu->win,
		env->menu->img, 0, 0);
}

t_menu	*init_menu(t_env *env)
{
	t_menu	*menu;

	menu = (t_menu *)malloc(sizeof(t_menu));
	if (!menu)
		handle_error("In init_menu: error allocation for menu.\n", 1);
	menu->mlx = env->mlx;
	menu->win = env->win;
	menu->width = 1;
	menu->height = HEIGHT;
	menu->img = mlx_new_image(env->mlx, menu->width, menu->height);
	menu->data_addr = mlx_get_data_addr(menu->img, &menu->bpp,
			&menu->line_len, &menu->endian);
	menu->pad_x = 75;
	menu->pad_y = 75;
	menu->x_center = menu->pad_x + (menu->width / 2);
	menu->x_left = menu->pad_x + INFO_INDENT;
	env->menu = menu;
	return (menu);
}
