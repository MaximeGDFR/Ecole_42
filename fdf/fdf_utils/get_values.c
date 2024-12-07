/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:29:30 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/04 16:14:27 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Opening error.\n", 1);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
		handle_error("Closing error.\n", 1);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Opening error.\n", 1);
	width = 0;
	line = get_next_line(fd);
	if (!line)
		handle_error("Invalid map (empty).\n", 1);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	while ((line = get_next_line(fd)) != NULL)
		free(line);
	if (close(fd) == -1)
		handle_error("Closing error.\n", 1);
	return (width);
}

void	get_z_min_max(char *line, t_map *map)
{
	char	**values;
	int		i;
	int		z;

	values = ft_split(line, ' ');
	i = 0;
	if (!values)
		handle_error("Error: map is not valid.\n", 1);
	while (values[i])
	{
		z = ft_atoi(values[i]);
		if (z < map->z_min)
			map->z_min = z;
		if (z > map->z_max)
			map->z_max = z;
		i++;
	}
	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
}
