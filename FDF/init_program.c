/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:43:53 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/12 09:43:54 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*init_env(char *filename)
{
	t_env	*env;
	char	*win_title;

	win_title = ft_strjoin("FdF Project - 42 School / mgodefro - ", filename);
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		handle_error("Error allocation for t_env.\n", 1);
	env->mlx = mlx_init();
	if (!env->mlx)
		handle_error("Error initialize mlx.\n", 1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, win_title);
	if (!env->win)
		handle_error("Error initializing window.\n", 1);
	free(env->win);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		handle_error("Error initializing image.\n", 1);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->line_len,
			&env->endian);
	env->map = NULL;
	env->cam = NULL;
	env->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!env->mouse)
		handle_error("Error initializing mouse.\n", 1);
	return (env);
}

t_cam	*init_cam(t_env *env)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		handle_error("Error initializing camera.\n", 1);
	cam->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
	cam->x_angle = -0.615472907;
	cam->y_angle = -0.523599;
	cam->z_angle = 0.615472907;
	cam->z_height = 1;
	cam->x_offset = 0;
	cam->y_offset = 0;
	cam->iso = 1;
	return (cam);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		handle_error("Error initializing map.\n", 1);
	map->height = 0;
	map->width = 0;
	map->matrix = NULL;
	map->z_min;
	map->z_max;
	return (map);
}
