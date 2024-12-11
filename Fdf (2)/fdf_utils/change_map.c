/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:22:37 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 20:57:10 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_map(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	clear_image(env);
	apply_projection(env);
	apply_center(env);
	draw_map(env);
}

void	change_map(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	clear_image(env);
	apply_projection(env);
	center_map(env);
	apply_center(env);
	draw_map(env);
}

void	reset_map(t_env *env)
{
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	clear_image(env);
	env->current_view = 1;
	env->x_offset = 0;
	env->y_offset = 0;
	calculate_scale(env);
	apply_projection(env);
	center_map(env);
	apply_center(env);
	draw_map(env);
}

void	clear_image(t_env *env)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			index = (y * env->img.size_line) + (x * (env->img.bpp / 8));
			*((unsigned int *)(env->img.data + index)) = 0x000000;
		}
	}
}
