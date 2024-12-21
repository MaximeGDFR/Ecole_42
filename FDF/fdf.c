/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:19:48 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/21 15:16:10 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_env	*env;

	if (argc != 2)
		handle_error("Error: argument number invalid.\n", 1);
	env = init_environnement(argv[1]);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT,
			"FDF Project - 42 School - mgodefro");
	if (!env->win)
		handle_error("In main: allocation error for env->win.\n", 1);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		handle_error("In main: allocation error for env->img.\n", 1);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp,
			&env->line_len, &env->endian);
	if (!env->data_addr)
		handle_error("In main: allocation error for env->data_addr.\n", 1);
	init_menu(env);
	draw_map(env);
	setup_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
