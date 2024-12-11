/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:31 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 15:40:29 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_env *env)
{
	if (env->points)
		free_points(env);
	if (env->win_ptr)
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	if (env->mlx_ptr)
		free(env->mlx_ptr);
	exit(EXIT_SUCCESS);
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
