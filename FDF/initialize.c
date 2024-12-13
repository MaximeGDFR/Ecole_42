#include "fdf.h"

t_env *init_environnement(void)
{
	t_env	*env;
}

t_point	*init_point(void)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(int));
	if (!point)
		handle_erreur("In init_point: error allocation point.\n", 1);
	point->x = 0;
	point->y = 0;
	point->z = 0;
	point->color = 0;
	point->reverse = 0;
	return (point);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(int));
	if (!map)
		handle_error("In init_map: error allocation map.\n", 1);
	allocate_matrix(map);
	map->height = get_height(filename);
	map->width = get_width(filename);
	fill_matrix(map);
	get_values_map(map->matrix);
	map->color_mode = 1,
	map->current_view = 1;
	return (map);
}

t_cam *init_cam(t_map *map)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_point));
	if (!cam)
		handle_error("In init_cam: error allocation cam.\n", 1);
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

	mouse = (t_mouse *)malloc(sizeof(int));
	if (!mouse)
		handle_error("In init_mouse: error allocation mouse.\n", 1);
	mouse->button = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->prev_x = 0;
	mouse->prev_y = 0;
	return (mouse);
}

int **allocate_matrix(t_map *map)
{
	int	y;
	int	x;

	map->matrix = (int **)malloc(sizeof(int *) * map->height);
	if (!map->matrix)
		handle_error("In allocate_matrix: error allocation map->matrix.\n", 1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		map->matrix[y] = (int *)malloc(sizeof(int) * map->width);
		if (!map->matrix[y])
			handle_error("In allocate_matrix: error allocation map->matrix[y].\n", 1);
		while (x < map->width)
		{
			map->matrix[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map->matrix);
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
		if (line != NULL || *line != '\0')
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
	int		width;
	int		first_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("In get_height: error open file.\n", 1);
	first_line = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
			compare_line(first_line, line);
		free(line);
	}
	close(fd);
	return (width);
}

int	compare_line(int first_line, char *line)
{
	int	width;

	width = count_values(line);
	if (width != first_line)
	{
		handle_error("In get_width: map is not rectangular.\n", 1);
		return (FALSE);
	}
	else
		return (TRUE);
}


/*
get_height -> lire file et height++ pour chaque ligne non vide
count_value -> compter le nombre de "valeurs" de la map
get_width -> lire file et width++ pour chaque valeurs lue
check_map -> verifier que toutes les lignes ont le même nombre de valeurs
fill_matrix -> lire une ligne + split + attribuer coordonnées / valeurs
get_values_map -> lire map et déterminer height / width / z_min / z_max / x_max / y_max
get_cam_values -> zoom / x_offset / y_offset / x_ang / y_ang / z_ang / z_height
*/

