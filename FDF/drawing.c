/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:45:43 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/16 21:32:26 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	i_part(float n)
{
	return ((int)n);
}

int	ft_ipart(float n)
{
	return ((int)n);
}

float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.f));
}

float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}



void	ft_draw_line_loop(t_point s, t_point e, float gradient, t_env *env)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (env->steep)
		{
			ft_put_pixel(env, ft_ipart(inter_y), x);
			ft_put_pixel(env, ft_ipart(inter_y) + 1, x);
		}
		else
		{
			ft_put_pixel(env, x, ft_ipart(inter_y));
			ft_put_pixel(env, x, ft_ipart(inter_y) + 1);
		}
		inter_y += gradient;
		x++;
	}
}

void ft_draw_line(t_point s, t_point e, t_env *env) {
    float dy = (float)(e.y - s.y);
    float dx = (float)(e.x - s.x);
    float gradient = dy / dx;
    float inter_y = (float)s.y;
    int x = s.x;

    if (dx == 0.0f) gradient = 1.f; // Si la ligne est verticale

    while (x <= e.x) {
        if (env->steep) {
            ft_put_pixel(env, (int)inter_y, x);
        } else {
            ft_put_pixel(env, x, (int)inter_y);
        }
        inter_y += gradient;
        x++;
    }
}*/

/*void	ft_rotate_x(int *y, int *z, double x_angle, int *x)
{
	int	prev_y;

	printf("Rotation X - Before: x: %d, y: %d, z: %d\n", *x, *y, *z);
	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
	printf("Rotation X - After: x: %d, y: %d, z: %d\n", *x, *y, *z);
}

void	ft_rotate_y(int *x, int *z, double y_angle, int *y)
{
	int	prev_x;

	printf("Rotation Y - Before: x: %d, y: %d, z: %d\n", *x, *y, *z);
	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
	printf("Rotation Y - After: x: %d, y: %d, z: %d\n", *x, *y, *z);
}

void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_point	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
	printf("Rotation Z - x: %d, y: %d\n", *x, *y);
}

t_point rotate(t_point point, double x_angle, double y_angle, double z_angle)
{
    t_point new_point;

    // Rotation autour de l'axe X
    new_point.y = point.y * cos(x_angle) + point.z * sin(x_angle);
    new_point.z = -point.y * sin(x_angle) + point.z * cos(x_angle);
    new_point.x = point.x;

    // Rotation autour de l'axe Y
    point = new_point; // mettre à jour point avec les nouvelles coordonnées après rotation X
    new_point.x = point.x * cos(y_angle) + point.z * sin(y_angle);
    new_point.z = -point.x * sin(y_angle) + point.z * cos(y_angle);
    new_point.y = point.y;

    // Rotation autour de l'axe Z
    point = new_point; // mettre à jour point avec les nouvelles coordonnées après rotation Y
    new_point.x = point.x * cos(z_angle) - point.y * sin(z_angle);
    new_point.y = point.x * sin(z_angle) + point.y * cos(z_angle);
    new_point.z = point.z;

    return new_point;
}*/


/*t_point	project(int x, int y, t_env *env)
{
	t_point	point;

	point.z = env->map->matrix[y][x].z;

	point.x = x * env->cam->zoom;
	point.y = y * env->cam->zoom;
	point.z *= env->cam->zoom / env->cam->z_height;
	point.x -= (env->map->width * env->cam->zoom) / 2;
	point.y -= (env->map->height * env->cam->zoom) / 2;

	printf("Avant rotation - x: %d, y: %d, z: %d\n", point.x, point.y, point.z);
	
	ft_rotate_x(&point.y, &point.z, env->cam->x_angle, &point.x);
	ft_rotate_y(&point.x, &point.z, env->cam->y_angle, &point.y);
	ft_rotate_z(&point.x, &point.y, env->cam->z_angle);

	printf("Après rotation - x: %d, y: %d, z: %d\n", point.x, point.y, point.z);
	
	point.x += WIDTH / 2 + env->cam->x_offset;
	point.y += HEIGHT / 2 + env->cam->y_offset;
	point.reverse = 0;
	return (point);
}

t_point project(int x, int y, t_env *env)
{
    t_point point;

    // Calcul des coordonnées avant rotation
    point.z = env->map->matrix[y][x].z;
    point.x = x * env->cam->zoom;
    point.y = y * env->cam->zoom;
    point.z *= env->cam->zoom / env->cam->z_height;
    point.x -= (env->map->width * env->cam->zoom) / 2;
    point.y -= (env->map->height * env->cam->zoom) / 2;

    printf("Avant rotation - x: %d, y: %d, z: %d\n", point.x, point.y, point.z);

    // Rotation de la carte
    point = rotate(point, env->cam->x_angle, env->cam->y_angle, env->cam->z_angle);

    printf("Après rotation - x: %d, y: %d, z: %d\n", point.x, point.y, point.z);

    // Ajustement de la position après rotation
    point.x += WIDTH / 2 + env->cam->x_offset;
    point.y += HEIGHT / 2 + env->cam->y_offset;
    point.reverse = 0;

    return point;
}*/

/*
void	ft_put_pixel(t_env *env, int x, int y)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * env->bpp / 8) + (y * env->line_len);
		env->data_addr[i] = 0xFF;
		env->data_addr[++i] = 0xFF;
		env->data_addr[++i] = 0xFF;
	}
}

void	ft_draw(t_map *map, t_env *env)
{
	int	x;
	int	y;
	t_point p1;
	t_point p2;

	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bpp / 8));
	y = 0;
//	if (env->cam->x_angle > 0)
//		y = map->height - 1;
	while (y < map->height)
	{
		x = 0;
//		if (env->cam->y_angle > 0)
//			x = map->width - 1;
		while (x < map->width)
		{
			p1 = project(x, y, env);
			p2 = project(x + 1, y + 1, env);
			if (x < map->width - 1 && y < map->height - 1)
				ft_draw_line(p1, p2, env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
//	ft_draw_instructions(env);
}
*/