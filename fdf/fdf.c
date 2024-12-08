/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:59:58 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 18:32:16 by maximegdfr       ###   ########.fr       */
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



void	change_projection(t_point *point, t_map *map)
{
	if (map->current_view < 1 || map->current_view > 11)
		map->current_view = 1;
	if (map->current_view == 1)
		project_front(point, map);
	else if (map->current_view == 2)
		projection_back(point, map);
	else if (map->current_view == 3)
		projection_top(point, map);
	else if (map->current_view == 4)
		projection_under(point, map);
	else if (map->current_view == 5)
		project_right(point, map);
	else if (map->current_view == 6)
		project_left(point, map);
	else if (map->current_view == 7)
		projection_iso(point, map);
	else if (map->current_view == 8)
		projection_perspective(point, 1000);
	else if (map->current_view == 9)
		projection_oblique(point, 30.0, OBLIQUE_REDUCTION);
	else if (map->current_view == 10)
		projection_dimetric(point);
	else if (map->current_view == 11)
		projection_trimetric(point, 30.0, 45.0, 60.0);
}

void	change_view(t_map *map)
{

	if (map->current_view == 1)
		map->current_view = FRONT_VIEW;
	else if (map->current_view == 2)
		map->current_view = BACK_VIEW;
	else if (map->current_view == 3)
		map->current_view = TOP_VIEW;
	else if (map->current_view == 4)
		map->current_view = UNDER_VIEW;
	else if (map->current_view == 5)
		map->current_view = RIGHT_VIEW;
	else if (map->current_view == 6)
		map->current_view = LEFT_VIEW;
	else if (map->current_view == 7)
		map->current_view = ISO_VIEW;
	else if (map->current_view == 8)
		map->current_view = PERSPECTIVE_VIEW;
	else if (map->current_view == 9)
		map->current_view = OBLIQUE_VIEW;
	else if (map->current_view == 10)
		map->current_view = DIMETRIC_VIEW;
	else if (map->current_view == 11)
		map->current_view = TRIMETRIC_VIEW;
}

void	center_map(t_map *map)
{
	double	scale_x;
	double	scale_y;

	scale_x = (WIDTH * SCALE) / (map->x_max - map->x_min);
	scale_y = (HEIGHT * SCALE) / (map->y_max - map->y_min);
	map->scale = fmin(scale_x, scale_y);

	map->x_center = (map->x_min + map->x_max) / 2.0;
	map->y_center = (map->y_min + map->y_max) / 2.0;

	map->x_center_offset = WIDTH / 2 - map->x_center * map->scale;
	map->y_center_offset = HEIGHT / 2 - map->y_center * map->scale;
}

void	apply_center(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y][x].x = (map->points[y][x].x - map->x_center)
				* map->scale + WIDTH / 2 + map->x_offset;
			map->points[y][x].y = (map->points[y][x].y - map->y_center)
				* map->scale + HEIGHT / 2 + map->y_offset;
			x++;
		}
		y++;
	}
}

void	apply_projection(t_map *map)
{
	int	y;
	int	x;
	int	original_z;

	map->x_min = map->x_max = 0;
	map->y_min = map->y_max = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			original_z = map->points[y][x].z;
			map->points[y][x].x = x * map->tile_size;
			map->points[y][x].y = y * map->tile_size;
			change_projection(&map->points[y][x], map);
			map->points[y][x].z = original_z;
			update_map_limits(map, x, y);
			x++;
		}
		y++;
	}
}

void	update_map_limits(t_map *map, int x, int y)
{
	if (map->points[y][x].x < map->x_min)
		map->x_min = map->points[y][x].x;
	if (map->points[y][x].x > map->x_max)
		map->x_max = map->points[y][x].x;
	if (map->points[y][x].y < map->y_min)
		map->y_min = map->points[y][x].y;
	if (map->points[y][x].y > map->y_max)
		map->y_max = map->points[y][x].y;
}

void	redraw_map(t_data *data, int menu_opened)
{
	mlx_clear_window(data->mlx, data->win);
	if (menu_opened == 1)
	{
		menu_background(data->mlx, data->win);
		open_menu(data->mlx, data->win, data->menu);
	}
	apply_projection(data->map);
	center_map(data->map);
	apply_center(data->map);
	draw_map(data, data->map);
}

int	get_sign(int value)
{
	if (value < 0)
		return (-1);
	else
		return (1);
}

void	update_coordinates(t_bresenham *bresenham, int *x, int *y)
{
	int	err_2;

	err_2 = bresenham->err * 2;
	if (err_2 > -bresenham->dy)
	{
		bresenham->err -= bresenham->dy;
		*x += bresenham->sx;
	}
	if (err_2 < bresenham->dx)
	{
		bresenham->err += bresenham->dx;
		*y += bresenham->sy;
	}
}

void	draw_line_bresenham(t_data *data, t_point p1, t_point p2)
{
	t_bresenham	bresenham;

	bresenham.dx = ft_abs(p2.x - p1.x);
	bresenham.dy = ft_abs(p2.y - p1.y);
	bresenham.sx = get_sign(p2.x - p1.x);
	bresenham.sy = get_sign(p2.y - p1.y);
	bresenham.err = bresenham.dx - bresenham.dy;
	while (1)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
		{
			mlx_pixel_put(data->mlx, data->win, p1.x, p1.y, 0xFFFFFF);
		}
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_coordinates(&bresenham, &p1.x, &p1.y);
	}
}

void	draw_lines(t_data *data, t_map *map, int x, int y)
{
	t_point	p1;
	t_point	p2;

	if (x + 1 < map->width)
	{
		p1 = map->points[y][x];
		p2 = map->points[y][x + 1];
		draw_line_bresenham(data, p1, p2);
	}
	if (y + 1 < map->height)
	{
		p1 = map->points[y][x];
		p2 = map->points[y + 1][x];
		draw_line_bresenham(data, p1, p2);
	}
}

void	draw_map(t_data *data, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_lines(data, map, x, y);
			x++;
		}
		y++;
	}
}

t_colors	*init_colors(void)
{
	t_colors	*colors;

	colors = malloc(sizeof(t_colors));
	if (!colors)
		handle_error("Allocation error.\n", 1);
	colors->color_1 = 0xFFFFFF;
	colors->color_2 = 0x0000FF;
	colors->cycle = 0;
	colors->use_gradient = 1;
	return (colors);
}

t_menu	*init_menu(void)
{
	t_menu	*menu;

	menu = malloc(sizeof(t_menu));
	if (!menu)
		handle_error("Allocation error.\n", 1);

	menu->title = "FDF COMMANDS";
	menu->command_b = "UP : Move up";
	menu->command_c = "DOWN : Move down";
	menu->command_d = "LEFT : Move left";
	menu->command_e = "RIGHT : Move right";
	menu->command_f = "P : Zoom in";
	menu->command_g = "M : Zoom out";
	menu->command_h = NULL;
	return (menu);
}


void	reset_map(t_data *data, int menu_opened)
{
	mlx_clear_window(data->mlx, data->win);
	data->map->current_view = 1;
	data->map->x_offset = 0;
	data->map->y_offset = 0;
	if (menu_opened == 1)
	{
		menu_background(data->mlx, data->win);
		open_menu(data->mlx, data->win, data->menu);
	}
	calculate_scale(data->map);
	apply_projection(data->map);
	center_map(data->map);
	apply_center(data->map);
	draw_map(data, data->map);
}