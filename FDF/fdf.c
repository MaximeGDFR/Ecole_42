/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:19:48 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/18 15:28:09 by mgodefro         ###   ########.fr       */
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
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FDF Project - 42 School - mgodefro");
	if (!env->win)
		handle_error("In main: allocation error for env->win.\n", 1);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		handle_error("In main: allocation error for env->img.\n", 1);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->line_len, &env->endian);
	if (!env->data_addr)
		handle_error("In main: allocation error for env->data_addr.\n", 1);

	draw_map(env);
	draw_menu(env);
	mlx_hook(env->win, 2, 1L << 0, keyboards_controls, env);
	mlx_hook(env->win, 4, 0, mouse_down, env);
	mlx_hook(env->win, 5, 0, mouse_move, env);
	mlx_hook(env->win, 6, 0, mouse_up, env);

	mlx_hook(env->win, 17, 0, quit_program, env);
	mlx_loop(env->mlx);
	return (0);
}
































/*	printf("_____ MAP _____\n");
	printf("Map height : %d\n", env->map->height);
	printf("Map width : %d\n", env->map->width);
	printf("Map z_min : %d\n", env->map->z_min);
	printf("Map z_max : %d\n", env->map->z_max);
	printf("Map x_max : %d\n", env->map->x_max);
	printf("Map y_max : %d\n", env->map->y_max);
	printf("Map current_view : %d\n", env->map->current_view);
	printf("Map color_mode : %d\n", env->map->color_mode);
	printf("\n_____ MATRICE _____\n");
	for (int i = 0; i < env->map->height; i++)
	{
		for (int j = 0; j < env->map->width; j++)
		{
			printf("%d ", env->map->matrix[i][j].x);
			}
	}
	printf("\n_____ CAM _____\n");
	printf("Cam zoom : %d\n", env->cam->zoom);
	printf("Cam x_offset : %d\n", env->cam->x_offset);
	printf("Cam y_offset : %d\n", env->cam->y_offset);
	printf("Cam x_angle : %f\n", env->cam->x_angle);
	printf("Cam y_angle : %f\n", env->cam->y_angle);
	printf("Cam z_angle : %f\n", env->cam->z_angle);
	printf("Cam z_height : %f\n", env->cam->z_height);
	printf("Cam iso : %d\n", env->cam->iso);
	printf("\n_____ MOUSE _____\n");
	printf("Mouse button : %d\n", env->mouse->button);
	printf("Mouse x : %d\n", env->mouse->x);
	printf("Mouse y : %d\n", env->mouse->y);
	printf("Mouse prev_x : %d\n", env->mouse->prev_x);
	printf("Mouse prev_y : %d\n", env->mouse->prev_y);*/