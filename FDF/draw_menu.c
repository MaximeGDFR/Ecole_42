/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:33:25 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/12 19:53:00 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_menu(t_menu *menu)
{
	int	i;

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
	i = 0;
	while (i < menu->width * menu->height)
	{
		*(unsigned int *)(menu->data_addr + i *
				(menu->bpp / 8)) = menu->color_background;
		i++;
	}
	write_menu(menu);
	mlx_put_image_to_window(menu->mlx, menu->win, menu->img, 0, 0);
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
