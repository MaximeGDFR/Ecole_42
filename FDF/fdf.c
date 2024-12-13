/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:19:48 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/13 15:39:20 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_env	*env;

	if (argc != 2)
		handle_error("Error: argument number invalid.\n", 1);
	env = init_env(argv[1]);
	printf("AFTER INIT_ENV IN MAIN\nheight : %d, width : %d\n", env->map->height, env->map->width);
	printf("Environment initialized\n");
	check_map(argv[1], env);
	printf("AFTER CHACK_MAP IN MAIN\nheight : %d, width : %d\n", env->map->height, env->map->width);
	draw_map(env);
	hook_controls(env);
	mlx_loop(env->mlx);
}
