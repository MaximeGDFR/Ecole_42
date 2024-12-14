/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:09:34 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/14 17:32:40 by maximegdfr       ###   ########.fr       */
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
	printf("Verify map BEFORE init_map: %p\n", env->map);
	env->map = init_map(filename);
	printf("Verify map AFTER init_map: %p\n", env->map);
	env->mouse = init_mouse();
	printf("Verify map BEFORE init_cam: %p\n", env->map);
	env->cam = init_cam(env->map);
	return(env);
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
	map->color_mode = 1,
	map->current_view = 1;
	return (map);
}

t_cam *init_cam(t_map *map)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		handle_error("In init_cam: error allocation cam.\n", 1);
	printf("At beginning of init_cam.\n");
	printf("WIDTH : %d / HEIGHT : %d\n", WIDTH, HEIGHT);
	printf("map: %p\n", map);
	printf("map->width : %d / map->height : %d\n", map->width, map->height);
	if (map->width == 0 || map->height == 0)
		handle_error("Error: map width or height is zero.\n", 1);

	cam->zoom = ft_min(WIDTH / map->width / 2,
			HEIGHT / map->height / 2);
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
	printf("mouse pointer: %p\n", (void *)mouse);
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

	printf("At the beginning of allocate_map_matrix :\n");
	printf("height : %d / width : %d\n", map->height, map->width);
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
			printf("Current y : %d / Current x : %d\n", y, x);
			if (y >= map->height || x >= map->width)
				handle_error("In allocate_map_matrix: index out of bounds while initializing map-matrix.\n", 1);
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
	printf("Map height : %d\n", map->height);
	lines = malloc(sizeof(char *) * map->height);
	if (!lines)
		handle_error("In read_file_to_matrix: error allocation.\n", 1);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("EOF reached.\n");
			break ;
		}
		printf("Read line %d: %s", count, line);
		if (line)
			lines[count++] = line;
	}
	close(fd);
	*line_count = count;
	printf("Matrix read:\n");
	for (int i = 0; i < *line_count; i++)
	{
		if (lines[i] == NULL)
		{
			printf("Error : Line %d is NULL.\n", i);
			exit(1);
		}
		printf("Line %d: %s", i, lines[i]);
	}
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
		printf("Proccessing line %d : %s\n", y, lines[y]);
		values = ft_split(lines[y], ' ');
		if (!values)
			handle_error("In fill_matrix: error split line.\n", 1);
		x = 0;
		while (x < map->width)
		{
			if (values[x] == NULL)
				handle_error("In fill_matrix: error parsing values in line.\n", 1);
			printf("Assigning matrix[%d][%d] -> x: %d, y: %d, z: %s\n", y, x, x, y, values[x]);
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

	printf("At beginning of get_map_values.\n");
	printf("x_max : %d, y_max: %d\n", map->width, map->height);
	printf("z_min : %d, z_max: %d\n", map->z_min, map->z_max);
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
	printf("At the end of get_map_values.\n");
	printf("x_max : %d, y_max: %d\n", map->width, map->height);
	printf("z_min : %d, z_max: %d\n", map->z_min, map->z_max);
	return(map);
}
