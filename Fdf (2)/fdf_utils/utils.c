/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:21:02 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 15:36:41 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_sign(int value)
{
	if (value < 0)
		return (-1);
	else
		return (1);
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	free_points(t_env *env)
{
	int	i;

	i = 0;
	if (env->points)
	{
		while (i < env->height)
		{
			if (env->points[i])
				free(env->points[i]);
		}
		free(env->points);
		env->points = NULL;
	}
}

void	*free_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	free_values(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}
