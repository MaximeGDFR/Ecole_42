/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:19:48 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/14 12:25:26 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_env	*env;

	if (argc != 2)
		handle_error("Error: argument number invalid.\n", 1);
	env = init_environnement(argv[1]);
	printf("_____ MAP _____\n");
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
	printf("Mouse prev_y : %d\n", env->mouse->prev_y);
	return (0);
}
