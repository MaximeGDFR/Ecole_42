/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:59:58 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 17:15:13 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		handle_error("Error: argument number invalid.\n", 1);
	data.map = load_map(argv[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		handle_error("Error: mlx_init failed.\n", 1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT,
			"FDF PROJECT - SCHOOL 42");
	if (!data.win)
		handle_error("Error: mlx_new_window failed.\n", 1);
	calculate_scale(data.map);
	print_map_info(data.map);

	print_bounds(data.map);
	print_map_info(data.map);
	apply_projection(data.map);
	center_map(data.map);
	apply_center(data.map);
	draw_map(&data, data.map);

	mlx_hook(data.win, 2, 1L << 0, handle_controls, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

t_map	*load_map(char *filename)
{
	t_map	*map;
	t_data	data;

	check_file_format(filename);

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		handle_error("Error: Memory allocation failed for map.\n", 1);

	set_map(map);
	data.map = map;
	init_data(&data, filename);
	return (map);
}

int	check_file_format(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (filename[i - 1] != 'f' || filename[i - 2] != 'd'
		|| filename[i - 3] != 'f' || filename[i - 4] != '.')
	{
		write(1, "Error: wrong file format.\n", 27);
		return (FALSE);
	}
	return (TRUE);
}

void	set_map(t_map *map)
{
	map->current_view = 1;
	map->height = 0;
	map->width = 0;
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	map->x_min = INT_MAX;
	map->x_max = INT_MIN;
	map->y_min = INT_MAX;
	map->y_max = INT_MIN;
	map->tile_size = 75;
	map->x_offset = 0;
	map->y_offset = 0;
	map->drawing_width = 0;
	map->drawing_height = 0;
	map->x_center_offset = 0;
	map->y_center_offset = 0;
	map->x_center = 0.0;
	map->y_center = 0.0;
	map->window_width_center = 0.0;
	map->window_height_center = 0.0;
	if (!map->points)
		map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
}

void	init_data(t_data *data, char *filename)
{
	data->map->height = get_height(filename);
	data->map->width = get_width(filename);
	allocate_matrix(data->map);
	fill_matrix(filename, data->map);
	data->menu = init_menu();
	data->colors = init_colors();
	data->menu_opened = 0;
}

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

void	allocate_matrix(t_map *map)
{
	int	i;

	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		handle_error("Error: Memory allocation for rows failed.\n", 1);
	i = 0;
	while (i < map->height)
	{
		map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->points[i])
			handle_error("Error: Memory allocation for columns failed.\n", 1);
		i++;
	}
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
		if (map->points[y][x].x < map->x_min)
			map->x_min = map->points[y][x].x;
		if (map->points[y][x].x > map->x_max)
			map->x_max = map->points[y][x].x;
		if (map->points[y][x].y < map->y_min)
			map->y_min = map->points[y][x].y;
		if (map->points[y][x].y > map->y_max)
			map->y_max = map->points[y][x].y;
		x++;
	}
	free_values(values);
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

void	calculate_scale(t_map *map)
{
	int	max_map_size;
	int	window_size;
	int	new_tile_size;
	int	padding;

	if (map->width == 0 || map->height == 0)
		handle_error("Invalid map dimensions.\n", 1);
	if (map->width > map->height)
		max_map_size = map->width;
	else
		max_map_size = map->height;
	if (WIDTH < HEIGHT)
		window_size = WIDTH;
	else
		window_size = HEIGHT;
	padding = window_size * 0.2;
	new_tile_size = (window_size - padding) / max_map_size;
	if (new_tile_size < map->tile_size)
		map->tile_size = new_tile_size;
	if (map->tile_size < 1)
		map->tile_size = 1;
}

