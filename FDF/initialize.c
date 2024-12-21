/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:09:34 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/21 13:58:11 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env *init_environnement(char *filename)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		handle_error("In init_env: error allocation env.\n", 1);
	env->points = init_point();
	env->map = init_map(filename);
	env->mouse = init_mouse();
	env->cam = init_cam(env->map);
	return (env);
}

t_point	*init_point(void)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		handle_error("In init_point: error allocation point.\n", 1);
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = 0;
	point->reverse = 0;
	return (point);
}

t_map	*init_map(char *filename)
{
	t_map	*map;
	char	**lines;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		handle_error("In init_map: error allocation map.\n", 1);
	map->height = get_height(filename);
	map->width = get_width(filename);
	allocate_map_matrix(map);
	lines = read_file_to_matrix(map, filename, &map->height);
	fill_matrix(map, lines);
	get_values_map(map);
	map->centered = 1;
	map->depth = 1.0;
	map->color_mode = 1;
	map->current_view = 4;
	return (map);
}

t_cam *init_cam(t_map *map)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		handle_error("In init_cam: error allocation cam.\n", 1);
	if (map->width == 0 || map->height == 0)
		handle_error("Error: map width or height is zero.\n", 1);

	cam->zoom = ft_min(WIDTH / map->width / 2.5,
			HEIGHT / map->height / 2.5);
	cam->x_angle = -0.615472907;
	cam->y_angle = -0.523599;
	cam->z_angle = 0.615472907;
	cam->z_height = 1;
	cam->x_offset = 0;
	cam->y_offset = 0;
	cam->iso = 1;
	return (cam);
}

t_mouse *init_mouse(void)
{
	t_mouse	*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!mouse)
		handle_error("In init_mouse: error allocation mouse.\n", 1);
	mouse->button = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->prev_x = 0;
	mouse->prev_y = 0;
	return (mouse);
}

void	init_point_values(t_point *point)
{
	if (point)
	{
		point->x = 0;
		point->y = 0;
		point->z = 0;
		point->color = 0;
		point->reverse = 0;
	}
}

void allocate_map_matrix(t_map *map)
{
	int	y;
	int	x;

	map->matrix = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->matrix)
		handle_error("In allocate_matrix: error allocation map->matrix.\n", 1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		map->matrix[y] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->matrix[y])
		{
			while (y-- > 0)
				free(map->matrix[y]);
			free(map->matrix);
			handle_error("In allocate_matrix: error allocation map->matrix[y].\n", 1);	
		}
		while (x < map->width)
		{
			if (y >= map->height || x >= map->width)
				handle_error("In allocate_map_matrix: index out of bounds while initializing map_matrix.\n", 1);
			init_point_values(&map->matrix[y][x]);
			x++;
		}
		y++;
	}
}



int	get_height(char *filename)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("In get_height : error open file.\n", 1);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL && *line != '\0')
			height++;
		else
			break ;
		free(line);
	}
	close(fd);
	return (height);
}

int	count_values(char *line)
{
	int		i;
	char	**values;
	int		count;

	values = ft_split(line, ' ');
	if (!values)
		handle_error("In count_values: error ft_split.\n", 1);
	i = 0;
	count = 0;
	while (values[i])
	{
		count++;
		i++;
	}
	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
	return (count);
}

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	int		first_line_width;
	int		current_width;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("In get_height: error open file.\n", 1);
	first_line_width = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		current_width = count_values(line);
		if (first_line_width == -1)
			first_line_width = current_width;
		else if (!compare_line(first_line_width, current_width))
		{
			free(line);
			handle_error("In get_width / compare_line: map is not rectangular.\n", 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (first_line_width);
}

int	compare_line(int first_line_width, int current_width)
{
	if (current_width != first_line_width)
		return (FALSE);
	else
		return (TRUE);
}

char	**read_file_to_matrix(t_map *map, char *filename, int *line_count)
{
	int		fd;
	char	*line;
	char	**lines;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("In read_file_to_matrix: error open file.\n", 1);
	lines = malloc(sizeof(char *) * map->height);
	if (!lines)
		handle_error("In read_file_to_matrix: error allocation.\n", 1);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line)
			lines[count++] = line;
	}
	close(fd);
	*line_count = count;
	return (lines);
}

void	fill_matrix(t_map *map, char **lines)
{
	char	**values;
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		values = ft_split(lines[y], ' ');
		if (!values)
			handle_error("In fill_matrix: error split line.\n", 1);
		x = 0;
		while (x < map->width)
		{
			if (values[x] == NULL)
				handle_error("In fill_matrix: error parsing values in line.\n", 1);
			map->matrix[y][x].x = x;
			map->matrix[y][x].y = y;
			map->matrix[y][x].z = ft_atoi(values[x]);
			free(values[x]);
			x++;
		}
		free(values);
		y++;
	}
}

t_map	*get_values_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->matrix[y][x].x > map->x_max)
				map->x_max = map->matrix[y][x].x;
			if (map->matrix[y][x].y > map->y_max)
				map->y_max = map->matrix[y][x].y;
			if (map->matrix[y][x].z < map->z_min)
				map->z_min = map->matrix[y][x].z;
			if (map->matrix[y][x].z > map->z_max)
				map->z_max = map->matrix[y][x].z;
			x++;
		}
		y++;
	}
	return (map);
}

void	setup_hooks(t_env *env)
{
	mlx_hook(env->win, 2, 1L << 0, keyboards_controls, env);
	mlx_hook(env->win, 4, 0, mouse_down, env);
	mlx_hook(env->win, 5, 0, mouse_move, env);
	mlx_hook(env->win, 6, 0, mouse_up, env);
	mlx_hook(env->win, 17, 0, quit_program, env);
}
