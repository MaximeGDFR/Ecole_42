/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:06:09 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/13 17:14:53 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("open error", 1);
	height = -1;
	line = get_next_line(fd);
	printf("IN WHILE OF GET_HEIGHT\n");
	while (line != NULL && *line != '\0')
	{
		height++;
		free(line);
		line = get_next_line(fd);
		if (line == NULL || *line == '\0')
			break ;
		printf("height = %d\n", height);
	}
	if (close(fd) == -1)
		handle_error("close error", 1);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("open error", 1);
	width = 0;
	line = get_next_line(fd);
	if (*line == '\0')
		handle_error("invalid map (empty)", 0);
	i = -1;
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	printf("width = %d\n", width);
	if (close(fd) == -1)
		handle_error("close error", 1);
	return (width);
}

void	fill_matrix(t_env *env, char *line, int y)
{
	char	**values;
	int		x;

	if (!env->cam)
		handle_error("Error: Camera is not initialized.\n", 1);
	if (!env->map)
		handle_error("Error: env->map is NULL\n", 1);
	values = ft_split(line, ' ');
	if (!values)
		handle_error("Error: invalid format.\n", 1);
	x = 0;
	while (x < env->map->width)
	{
		env->map->matrix[y][x].x = x * env->cam->zoom;
		env->map->matrix[y][x].y = y * env->cam->zoom;
		env->map->matrix[y][x].z = ft_atoi(values[x]);
		if (env->map->matrix[y][x].z < env->map->z_min)
			env->map->z_min = env->map->matrix[y][x].z;
		if (env->map->matrix[y][x].z > env->map->z_max)
			env->map->z_max = env->map->matrix[y][x].z;
		x++;
	}
	free_values(values);
}

void	check_map(char *filename, t_env *env)
{
	int		fd;
	char	*line;
	int		i;

	if (env->map->width <= 0 || env->map->height <= 0)
		handle_error("Invalid map dimensions\n", 1);
	printf("Map width: %d, height: %d\n", env->map->width, env->map->height);
	allocate_matrix(env->map);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error("Open error\n", 1);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && *line != '\0')
	{
		fill_matrix(env, line, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (close(fd) == -1)
		handle_error("Close error\n", 1);
}

void allocate_matrix(t_map *map)
{
	int	i;
	int	j;

	map->matrix = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->matrix)
		handle_error("Failed to allocate memory for matrix rows.\n", 1);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		map->matrix[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->matrix[i])
			handle_error("Failed to allocate memory for matrix columns.\n", 1);
		while (j < map->width)
		{
			map->matrix[i][j].z = 0;
			j++;
		}
		i++;
	}
	printf("Matrix allocated with dimensions: %d x %d.\n", map->width, map->height);
}
