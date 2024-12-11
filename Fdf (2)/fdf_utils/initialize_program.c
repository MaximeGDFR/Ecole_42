/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:40:20 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 21:34:01 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_program(t_env *env, char *filename)
{
	init_point_bresenham(&env->point, &env->bresenham);
	init_image(&env->img);
	init_env_first(env, filename);
	init_env_second(env);
}

void	init_point_bresenham(t_point *point, t_bresenham *bresenham)
{
	point->x = 0;
	point->y = 0;
	point->y = 0;
	point->color = 0;
	bresenham->err = 0;
	bresenham->dx = 0;
	bresenham->dy = 0;
	bresenham->sx = 1;
	bresenham->sy = 1;
}

void	init_image(t_image *image)
{
	if (image == NULL)
		return ;
	image->img_ptr = NULL;
	image->data = NULL;
	image->bpp = 32;
	image->endian = 0;
	image->size_line = 0;
}

void	init_env_first(t_env *env, char *filename)
{
	env->height = get_height(filename);
	env->width = get_width(filename);
	env->zoom = 1.0;
	env->current_view = 7;
	env->color_mode = 1;
	env->angle_x = 0.0;
	env->angle_y = 0.0;
	env->angle_z = 0.0;
	env->points = NULL;
	env->x_max = INT_MIN;
	env->x_min = INT_MAX;
	env->y_max = INT_MIN;
	env->y_min = INT_MAX;
	env->z_max = INT_MIN;
	env->z_min = INT_MAX;
}

void	init_env_second(t_env *env)
{
	env->tile_size = 75;
	env->x_offset = 0;
	env->y_offset = 0;
	env->drawing_width = 0;
	env->drawing_height = 0;
	env->x_center_offset = 0;
	env->y_center_offset = 0;
	env->x_center = 0.0;
	env->y_center = 0.0;
	env->win_width_center = 0.0;
	env->win_height_center = 0.0;
}
