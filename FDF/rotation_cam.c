/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:51:07 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/13 16:00:04 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

void	rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

void	rotate_z(int *x, int *y, double z_angle)
{
	t_point	prev_points;

	prev_points.x = *x;
	prev_points.y = *y;
	*x = prev_points.x * cos(z_angle) - prev_points.y * sin(z_angle);
	*y = prev_points.x * sin(z_angle) + prev_points.y * cos(z_angle);
}

void	apply_camera_transformation(t_point *point, t_env *env)
{
	rotate_x(&point->y, &point->z, env->cam->x_angle);
	rotate_y(&point->x, &point->z, env->cam->y_angle);
	rotate_z(&point->x, &point->y, env->cam->z_angle);
}

t_point	projection(int x, int y, t_env *env)
{
	t_point	point;

	if (!env->map->matrix)
		handle_error("Matrix is NULL in projection.\n", 1);
	point.z = env->map->matrix[y][x].z;
	point.x = x * env->cam->zoom;
	point.y = y * env->cam->zoom;
	//point.z = env->cam->zoom / env->cam->z_height;
	// Centrage de la carte
	point.x -= (env->map->width * env->cam->zoom) / 2;
	point.y -= (env->map->height * env->cam->zoom) / 2;
	// Gestion des projections
	change_projection(&point, env);
	// Gestion rotations
	apply_camera_transformation(&point, env);
	// Ajustements finaux
	point.x += WIDTH / 2 + env->cam->x_offset;
	point.y += (HEIGHT + env->map->height / 2 * env->cam->zoom) / 2
		+ env->cam->y_offset;
	point.reverse = 0;
	apply_color_mode(&point, env);
	return (point);
}
