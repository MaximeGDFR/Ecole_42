/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:33:25 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/18 18:35:53 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_env *env)
{
	int	i;

	if (!env->menu)
		handle_error("In init_menu: menu is NULL.\n", 1);
	env->menu->win = env->win;
	i = 0;
	while (i < env->menu->width * env->menu->height)
	{
		*(unsigned int *)(env->menu->data_addr + i *
				(env->menu->bpp / 8)) = env->menu->color_background;
		i++;
	}
	write_menu(env->menu);
	mlx_put_image_to_window(env->menu->mlx, env->menu->win, env->menu->img, 0, 0);
}

void	write_menu(t_menu *menu)
{
	int	current_line;

	current_line = 0;
	display_projection_infos(menu, &current_line);
	display_map_infos(menu, &current_line);
	display_fdf_keyboards(menu, &current_line);
	display_fdf_mouse(menu, &current_line);
}

t_menu	*init_menu(t_env *env)
{
	printf("=== BEGINNING INIT_MENU ===\n");
	printf("env : %p\n", env);
	printf("env->menu : %p\n", env->menu);
	t_menu	*menu;

	menu = (t_menu *)malloc(sizeof(t_menu));
	if (!menu)
		handle_error("In init_menu: error allocation for menu>\n", 1);
	printf("=== AFTER ALLOCATION INIT_MENU ===\n");
	printf("env : %p\n", env);
	printf("env->menu : %p\n", env->menu);
	menu->mlx = env->mlx;
	menu->width = 30 * AVG_CHAR_WIDTH;
	menu->height = HEIGHT;
	menu->img = mlx_new_image(menu->mlx, menu->width, menu->height);
	if (!menu->img)
		handle_error("Error initializing image for menu.\n", 1);
	menu->data_addr = mlx_get_data_addr(menu->img, &menu->bpp, &menu->line_len,
			&menu->endian);
	menu->pad_x = WIDTH * 0.075;
	menu->pad_y = HEIGHT * 0.1;
	menu->x_center = menu->pad_x + (menu->width / 2);
	menu->x_left = menu->pad_x + INFO_INDENT;
	menu->color_background = 0x80000000;
	return (menu);
}

/*void	put_background_menu(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->menu->width * env->menu->height)
	{
		*(unsigned int *)(env->menu->data_addr + i *
				(env->menu->bpp / 8)) = env->menu->color_background;
		i++;
	}
}

void	write_menu(t_env *env)
{
	int	current_line;

	current_line = 0;
	put_background_menu(env);
	display_projection_infos(menu, &current_line);
	display_map_infos(menu, &current_line);
	display_fdf_keyboards(menu, &current_line);
	display_fdf_mouse(menu, &current_line);
}



VERIFIER LUTILISATION DE LA SOURIS AVEC LE CALCUL DE DEPLACEMENT ET LA MISE A JOUR DE LA MAP (rotate_x, rotate_y, rotate_z)*/