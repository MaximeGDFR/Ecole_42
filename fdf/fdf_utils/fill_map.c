/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:29 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 15:54:08 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_row(t_map *map, char *line, int y)
{
	char	**values;
	int		x;

	values = ft_split(line, ' ');
	if (!values)
		handle_error("Error: invalid format.\n", 1);
	x = 0;
	while (x < map->width)
	{
		map->points[y][x].x = x * map->tile_size;
		map->points[y][x].y = y * map->tile_size;
		map->points[y][x].z = ft_atoi(values[x]);
		map->points[y][x].color = calculate_color(map->points[y][x].z, map);
		x++;
	}
	free_values(values);
}

void	fill_matrix(char *filename, t_map *map)
{
	char	*line;
	int		fd;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Opening error.\n", 1);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (y >= map->height)
			handle_error("Error: rows not matching height.\n", 1);
		fill_row(map, line, y);
		get_z_min_max(line, map);
		free(line);
		y++;
	}
	if (y != map->height)
		handle_error("Error: rows not matching height.\n", 1);
	if (close(fd) < 0)
		handle_error("Closing error.\n", 1);
}

t_map	*init_map(char *filename)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		handle_error("Allocation error.\n", 1);

	map->height = get_height(filename);
	map->width = get_width(filename);
	map->current_view = 1;
	calculate_scale(map);

	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		handle_error("Allocation error.\n", 1);
	i = 0;
	while (i < map->height)
	{
		map->points[i] = malloc(sizeof(t_point) * map->width);
		if (!map->points[i])
			handle_error("Allocation error.\n", 1);
		i++;
	}
	fill_matrix(filename, map);
	center_map(map);
	return (map);
}
/*
Vue front ok
Vue back décalée a gauche
Vue top ok
Vue under décalée vers le haut
Vue right décalée à gauche
Vue left décalée à gauche
Vue iso légèrement décalée à gauche
Vue perspective ok
Vue oblique ok
Vue dimetric légèrement décalée à gauche
Vue trimetric légèrement décalée à gauche
*/