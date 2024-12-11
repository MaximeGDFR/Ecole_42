/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:19:48 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 21:38:36 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		handle_error("Error: argument number invalid.\n", 1);
	init_program(&env, argv[1]);
	allocate_matrix(&env);
	fill_matrix(argv[1], &env);
	env.mlx_ptr = mlx_init();
	if (!env.mlx_ptr)
		handle_error("Error: mlx initialization failed.\n", 1);
	env.win_ptr = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT,
			"FDF Project - 42 School - mgodefro");
	if (!env.win_ptr)
		handle_error("Error: window creation failed.\n", 1);
	env.img.img_ptr = mlx_new_image(env.mlx_ptr, WIDTH, HEIGHT);
	if (!env.img.img_ptr)
		handle_error("Error: image creation failed.\n", 1);
	env.img.data = mlx_get_data_addr(env.img.img_ptr, &env.img.bpp,
			&env.img.size_line, &env.img.endian);
	if (!env.img.data)
		handle_error("Error: mlx_get_data_addr failed.\n", 1);


	calculate_scale(&env);
	apply_projection(&env);
	center_map(&env);
	apply_center(&env);
	draw_map(&env);

	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
	mlx_hook(env.win_ptr, 2, 1L << 0, key_controls, &env);
	mlx_hook(env.win_ptr, 17, 0L, close_window, &env);
	mlx_loop(env.mlx_ptr);
	free_points(&env);
	return (0);
}
