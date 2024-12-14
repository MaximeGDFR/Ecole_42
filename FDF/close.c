/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:06:30 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/14 12:24:26 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	quit_program(t_env *env)
{
	int	x;
	int	y;

	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	free(env->cam);
	free(env->mouse);
	y = -1;
	while (++y < env->map->height)
	{
		x = -1;
		while (++x < env->map->width)
			free(env->map->matrix[y][x]);
		free(env->map->matrix[y]);
	}
	free(env->map->matrix);
	free(env->map);
	free(env->mlx);
	free(env);
	exit(1);
	return (0);
}*/

void	handle_error(char *msg_err, int syst_funct)
{
	if (!syst_funct)
		write (2, msg_err, ft_strlen(msg_err));
	else
		write (1, msg_err, ft_strlen(msg_err));
	exit(-1);
}
