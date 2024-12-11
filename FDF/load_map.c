/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:20:06 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/12 00:48:12 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_point(char **line, t_env *env, int *x, int y)
{
	int		z;

	z = ft_atoi(*line);
	new_point(*x, y, z, env);
	if (z < env->map->z_min)
		env->map->z_min = z;
	if (z > env->map->z_max)
		env->map->z_max = z;
	if (z < 0)
	{
		(*line)++;
		z = -z;
	}
	while (z > 9)
	{
		z = z / 10;
		(*line)++;
	}
	*x -= 1;
	(*line)++;
}

int		open_file(t_env *env, char *filename)
{
	int		fd;

	fd = open(filename, __O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_file(fd, env));
}

int		read_file(int fd, t_env *env)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		x = 0;
		while (*line != '\0')
		{
			if (*line == ' ')
				line++;
			else
			{
				if (*line != '-' && (*line < '0' || *line > '9'))
					return (0);
				read_point(&line, env, &x, y);
			}
		}
		end_point(env);
		y -= 1;
	}
	env->map->x_max = -x;
	env->map->y_max = -y;
	return (1);
}
