/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:06:30 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/17 16:19:19 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int quit_program(t_env *env)
{
    int y;

    if (env)
    {
        if (env->img)
            mlx_destroy_image(env->mlx, env->img);
        if (env->win)
            mlx_destroy_window(env->mlx, env->win);
        if (env->cam)
            free(env->cam);
        if (env->mouse)
            free(env->mouse);
        if (env->map)
        {
            y = -1;
            while (++y < env->map->height)
            {
                if (env->map->matrix[y])
                    free(env->map->matrix[y]);
            }
            free(env->map->matrix);
            free(env->map);
        }
        if (env->mlx)
            free(env->mlx);
        free(env);
    }
    exit(0);
    return (0);
}


void	handle_error(char *msg_err, int syst_funct)
{
	if (!syst_funct)
		write (2, msg_err, ft_strlen(msg_err));
	else
		write (1, msg_err, ft_strlen(msg_err));
	exit(-1);
}
