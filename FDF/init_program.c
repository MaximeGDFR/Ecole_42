/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:43:53 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/13 16:57:21 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "fdf.h"

t_env	*init_env(char *filename)
{
	t_env	*env;
	char	*win_title;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		handle_error("Error allocation for t_env.\n", 1);
	ft_bzero(env, sizeof(t_env));
	win_title = ft_strjoin("FdF Project - 42 School / mgodefro - ", filename);
	env->mlx = mlx_init();
	if (!env->mlx)
		handle_error("Error initialize mlx.\n", 1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, win_title);
	if (!env->win)
		handle_error("Error initializing window.\n", 1);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		handle_error("Error initializing image.\n", 1);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->line_len,
			&env->endian);
	env->map = init_map();
	env->cam = init_cam(env, filename);
	env->mouse = init_mouse();
	return (env);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		handle_error("Error initializing map.\n", 1);
	ft_bzero(map, sizeof(t_map));
	return (map);
}

t_cam	*init_cam(t_env *env, char *filename)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		handle_error("Error initializing camera.\n", 1);
	ft_bzero(cam, sizeof(t_cam));
	env->map->width = get_width(filename);
	env->map->height = get_height(filename);
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

t_mouse	*init_mouse(void)
{
	t_mouse	*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!mouse)
		handle_error("Error initializing mouse.\n", 1);
	ft_bzero(mouse, sizeof(t_mouse));
	return (mouse);
}

t_menu *init_menu(void)
{
    t_menu *menu;

    printf("Initializing menu\n");

    // Allouer mémoire pour t_menu
    menu = (t_menu *)malloc(sizeof(t_menu));
    if (!menu)
        handle_error("Error initializing menu.\n", 1);

    // Initialiser toutes les variables de t_menu à zéro
    ft_bzero(menu, sizeof(t_menu));

    // Initialisation spécifique des variables si nécessaire
    menu->color_background = 0x000000;  // Par exemple, la couleur de fond

    printf("Menu initialized\n");

    return menu;
}*/