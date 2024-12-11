/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:06:09 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/12 00:31:35 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	check_open_file(fd, filename);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	check_open_file(fd, filename);
	width = 0;
	line = get_next_line(fd);
	if (!line)
		handle_error("Invalid map (empty).\n", 1);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	close(fd);
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
	free(values);
}

void	fill_matrix(int **row, char *line, int width)
{
	char	**values;
	int		i;

	values = ft_split(line, ' ');
	if (!values)
		handle_error("Error allocation in fill_matrix.\n", 1);		
	i = 0;
	while (values[i] && i < width)
	{
		row[i] = malloc(sizeof(int) * 2);
		if (!row[i])
			handle_error("Error allocation in fill_matrix.\n", 1);
		row[i][0] = ft_atoi(values[i]);
		free(values[i]);
		i++;
	}
	if (i != width || values[i])
		handle_error("Error: map format is not valid.\n", 1);
	free(values);
}

void	check_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->width = get_width(filename);
	map->height = get_height(filename);
	check_open_file(fd, filename);
	map->matrix = malloc(sizeof(int **) * map->height);
	if (!map->matrix)
		handle_error("Error allocation in check_map.\n", 1);
	i = -1;
	while (++i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			handle_error("Error: line is empty.\n", 1);
		map->matrix[i] = malloc(sizeof(int *) * map->width);
		if (!map->matrix[i])
			handle_error("Error allocation in check_map.\n", 1);
		fill_matrix(map->matrix[i], line, map->width);
		free(line);
	}
	get_z_min_max(filename, map);
	close(fd);
}
