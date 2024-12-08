/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:53:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 11:49:27 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_text_width(const char *text)
{
	int	width;

	width = 0;
	while (text[width] != '\0')
		width++;
	return (width * 10);
}

void	open_menu(void *mlx, void *win, t_menu *menu)
{
	int	y;

	y = MENU_PADDING;
	mlx_string_put(mlx, win, MENU_PADDING, y, 0xFFFFFF, menu->title);
	y += 20;
	if (menu->command_a != NULL)
		y = display_command(mlx, win, menu->command_a, y);
	if (menu->command_b != NULL)
		y = display_command(mlx, win, menu->command_b, y);
	if (menu->command_c != NULL)
		y = display_command(mlx, win, menu->command_c, y);
	if (menu->command_d != NULL)
		y = display_command(mlx, win, menu->command_d, y);
	if (menu->command_e != NULL)
		y = display_command(mlx, win, menu->command_e, y);
	if (menu->command_f != NULL)
		y = display_command(mlx, win, menu->command_f, y);
	if (menu->command_g != NULL)
		y = display_command(mlx, win, menu->command_g, y);
}

int	display_command(void *mlx, void *win, char *command, int y)
{
	mlx_string_put(mlx, win, MENU_PADDING, y, 0xFFFFFF, command);
	y += 20;
	return (y);
}

void	menu_background(void *mlx, void *win)
{
	int	x;
	int	y;
	int	menu_width;

	if (mlx == NULL || win == NULL)
		handle_error("No window or mlx to draw on.\n", 1);
	menu_width = WIDTH * 0.1;
	x = 0;
	while (x < menu_width)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(mlx, win, x, y, 0x101010);
			y++;
		}
		x++;
	}
}
