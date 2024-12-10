/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:21:02 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 00:42:42 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int dummy_event(void *param)
{
    (void)param; // Aucun paramètre utilisé ici
    return (0);
}


/* Utility fonctions */
int	check_file_format(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i < 4 || filename[i - 1] != 'f' || filename[i - 2] != 'd'
		|| filename[i - 3] != 'f' || filename[i - 4] != '.')
	{
		write(1, "Error: wrong file format.\n", 27);
		return (FALSE);
	}
	return (TRUE);
}

void free_points(t_env *env)
{
    if (env->points)
    {
        for (int i = 0; i < env->height; i++)
        {
            if (env->points[i])
                free(env->points[i]);
        }
        free(env->points);
        env->points = NULL;
    }
}



int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void init_program(t_env *env) {
    env->mlx_ptr = mlx_init();
    if (!env->mlx_ptr)
        handle_error("Error: mlx initialization failed.\n", 1);

    env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "FDF");
    if (!env->win_ptr)
        handle_error("Error: window creation failed.\n", 1);

    env->img.img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
    if (!env->img.img_ptr)
        handle_error("Error: image creation failed.\n", 1);

    env->img.data = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
    if (!env->img.data) {
        fprintf(stderr, "Error: mlx_get_data_addr failed.\n");
        exit(EXIT_FAILURE); // Utiliser exit pour terminer le programme
    }
	init_env(env);
}



void init_env(t_env *env) {
    // Affichage des valeurs avant initialisation
    printf("Initializing environment...\n");
    printf("Before initialization:\n");
    printf("mlx_ptr: %p\n", env->mlx_ptr);
    printf("img.img_ptr: %p\n", env->img.img_ptr);
    printf("width: %d, height: %d\n", env->width, env->height);
    printf("zoom: %.2f, current_view: %d\n", env->zoom, env->current_view);
    printf("angle_x: %.2f, angle_y: %.2f, angle_z: %.2f\n", env->angle_x, env->angle_y, env->angle_z);
    printf("x_max: %d, x_min: %d, y_max: %d, y_min: %d\n", env->x_max, env->x_min, env->y_max, env->y_min);
    printf("z_max: %d, z_min: %d\n", env->z_max, env->z_min);
    printf("tile_size: %d\n", env->tile_size);

    env->img.data = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, &env->img.size_line, &env->img.endian);
    env->width = 0;
    env->height = 0;
    env->zoom = 1.0;
	env->current_view = 7;
    env->angle_x = 0.0;
    env->angle_y = 0.0;
    env->angle_z = 0.0;
    env->points = NULL;
	env->x_max = INT_MIN;
	env->x_min = INT_MAX;
	env->y_max = INT_MIN;
	env->y_min = INT_MAX;
	env->z_max = INT_MIN;
	env->z_min = INT_MAX;
	env->tile_size = 75;
	env->x_offset = 0;
	env->y_offset = 0;
	env->drawing_width = 0;
	env->drawing_height = 0;
	env->x_center_offset = 0;
	env->y_center_offset = 0;
	env->x_center = 0.0;
	env->y_center = 0.0;
	env->win_width_center = 0.0;
	env->win_height_center = 0.0;

    // Affichage des valeurs après initialisation
    printf("After initialization:\n");
    printf("mlx_ptr: %p\n", env->mlx_ptr);
    printf("img.img_ptr: %p\n", env->img.img_ptr);
    printf("width: %d, height: %d\n", env->width, env->height);
    printf("zoom: %.2f, current_view: %d\n", env->zoom, env->current_view);
    printf("angle_x: %.2f, angle_y: %.2f, angle_z: %.2f\n", env->angle_x, env->angle_y, env->angle_z);
    printf("x_max: %d, x_min: %d, y_max: %d, y_min: %d\n", env->x_max, env->x_min, env->y_max, env->y_min);
    printf("z_max: %d, z_min: %d\n", env->z_max, env->z_min);
    printf("tile_size: %d\n", env->tile_size);
}



int close_window(void *param)
{
    (void)param;
    printf("Closing the window...\n");
    exit(EXIT_SUCCESS);
    return (0);
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
	printf("Height : %d\n", height);
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
	free_lines(fd);
	if (close(fd) == -1)
		handle_error("Closing error.\n", 1);
	printf("Width : %d\n", width);
	return (width);
}

void	*free_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void free_values(char **values)
{
    int i = 0;
    while (values[i])
    {
        free(values[i]);
        i++;
    }
    free(values);
}















// Fonction pour interpoler entre deux couleurs
int interpolate_color(int start_color, int end_color, float ratio) {
    int r = ((start_color >> 16) & 0xFF) * (1 - ratio) + ((end_color >> 16) & 0xFF) * ratio;
    int g = ((start_color >> 8) & 0xFF) * (1 - ratio) + ((end_color >> 8) & 0xFF) * ratio;
    int b = (start_color & 0xFF) * (1 - ratio) + (end_color & 0xFF) * ratio;
    return (r << 16) | (g << 8) | b;
}

int calculate_color(int z, t_env *env, t_colors color_mode)
{
    float ratio;

    // Normaliser la valeur Z entre [0,1]
    if (z < env->z_min)
        return WHITE; // Tout en blanc si z est inférieur à min_z
    if (z > env->z_max)
        return WHITE; // Tout en blanc si z est supérieur à max_z

    ratio = (float)(z - env->z_min) / (env->z_max - env->z_min);

    int start_color, end_color;
    get_gradient_colors(color_mode, &start_color, &end_color);

    return interpolate_color(start_color, end_color, ratio);
}

// Fonction pour obtenir les couleurs de début et de fin en fonction du mode
void get_gradient_colors(t_colors color_mode, int *start_color, int *end_color) {
    switch (color_mode) {
        case SOLID_WHITE:
            *start_color = WHITE;
            *end_color = WHITE;
            break;
        case SOLID_BLUE:
            *start_color = BLUE;
            *end_color = BLUE;
            break;
        case SOLID_YELLOW:
            *start_color = YELLOW;
            *end_color = YELLOW;
            break;
        case FOREST_GRADIENT:
            *start_color = FOREST_START;
            *end_color = FOREST_END;
            break;
        case OCEAN_GRADIENT:
            *start_color = OCEAN_START;
            *end_color = OCEAN_END;
            break;
        case SUNSET_GRADIENT:
            *start_color = SUNSET_START;
            *end_color = SUNSET_END;
            break;
        default:
            *start_color = WHITE; // Valeur par défaut
            *end_color = WHITE;   // Valeur par défaut
            break;
    }
}

void put_pixel(t_point p, t_env *env)
{
    if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
    {
        int index = (p.y * env->img.size_line + p.x * (env->img.bpp / 8));
        *((int *)(env->img.data + index)) = p.color;  // Utilisez la couleur calculée pour chaque pixel
    }
    else
    {
        printf("Warning: Coordinates out of bounds for put_pixel: (%d, %d)\n", p.x, p.y);
    }
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

void	draw_line_bresenham(t_env *env, t_point p1, t_point p2)
{
	t_bresenham	bresenham;
	t_point		current_point;

	bresenham.dx = ft_abs(p2.x - p1.x);
	bresenham.dy = ft_abs(p2.y - p1.y);
	bresenham.sx = get_sign(p2.x - p1.x);
	bresenham.sy = get_sign(p2.y - p1.y);
	bresenham.err = bresenham.dx - bresenham.dy;
	while (1)
	{
		current_point.x = p1.x;
		current_point.y = p1.y;
		current_point.z = p1.z;
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
		{
			put_pixel(current_point, env);
		}
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		update_coordinates(&bresenham, &p1.x, &p1.y);
	}
}

void	draw_lines(t_env *env, int x, int y)
{
	t_point	p1;
	t_point	p2;

	if (x + 1 < env->width)
	{
		p1 = env->points[y][x];
		p2 = env->points[y][x + 1];
		draw_line_bresenham(env, p1, p2);
	}
	if (y + 1 < env->height)
	{
		p1 = env->points[y][x];
		p2 = env->points[y + 1][x];
		draw_line_bresenham(env, p1, p2);
	}
}

void	draw_map(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			draw_lines(env, x, y);
			x++;
		}
		y++;
	}
}

// Alloue la mémoire pour la matrice de points
void allocate_matrix(t_env *env)
{
    int i;

    env->points = (t_point **)malloc(sizeof(t_point *) * env->height);
    if (!env->points)
        handle_error("Error: Memory allocation for rows failed.\n", 1);
    
    i = 0;
    while (i < env->height)
    {
        env->points[i] = (t_point *)malloc(sizeof(t_point) * env->width);
        if (!env->points[i])
            handle_error("Error: Memory allocation for columns failed.\n", 1);
        i++;
    }
}

// Fonction pour remplir la matrice de points à partir du fichier
void fill_matrix(char *filename, t_env *env) {
    char *line;
    int fd;
    int y;

    fd = open(filename, O_RDONLY);
    if (fd < 0) handle_error("Opening error.\n", 1);

    y = 0;
    
    while (1) {
        line = get_next_line(fd);
        if (line == NULL) break;

        if (y >= env->height) handle_error("Error: rows not matching height.\n", 1);

        fill_row(env, line, y);
        get_z_min_max(line, env);
        
        free(line);
        y++;
        
        printf("Filled row %d\n", y); // Debug info for each filled row
    }

    if (y != env->height) handle_error("Error: rows not matching height.\n", 1);

    if (close(fd) < 0) handle_error("Closing error.\n", 1);
}

// Remplie une ligne de la matrice de points
void fill_row(t_env *env, char *line, int y)
{
    char    **values;
    int     x;

    values = ft_split(line, ' ');
    if (!values)
        handle_error("Error: invalid format.\n", 1);
    
    x = 0;
    while (x < env->width)
    {
        env->points[y][x].x = x * env->tile_size;
        env->points[y][x].y = y * env->tile_size;
        env->points[y][x].z = ft_atoi(values[x]);
        env->points[y][x].color = calculate_color(env->points[y][x].z, env, env->color_mode);

        // Mise à jour des min/max
        if (env->points[y][x].x < env->x_min)
            env->x_min = env->points[y][x].x;
        if (env->points[y][x].x > env->x_max)
            env->x_max = env->points[y][x].x;
        if (env->points[y][x].y < env->y_min)
            env->y_min = env->points[y][x].y;
        if (env->points[y][x].y > env->y_max)
            env->y_max = env->points[y][x].y;
        x++;
    }
    free_values(values);
}

// Récupère les min et max des altitudes (z) des points
void get_z_min_max(char *line, t_env *env)
{
    char    **values;
    int     i;
    int     z;

    values = ft_split(line, ' ');
    i = 0;
    if (!values)
        handle_error("Error: map is not valid.\n", 1);

    while (values[i])
    {
        z = ft_atoi(values[i]);
        if (z < env->z_min)
            env->z_min = z;
        if (z > env->z_max)
            env->z_max = z;
        i++;
    }
    i = 0;
    while (values[i])
        free(values[i++]);
    free(values);
}

void calculate_scale(t_env *env)
{
	int	max_map_size;
	int	window_size;
	int	new_tile_size;
	int	padding;

	if (env->width == 0 || env->height == 0)
		handle_error("Invalid map dimensions.\n", 1);
	if (env->width > env->height)
		max_map_size = env->width;
	else
		max_map_size = env->height;
	if (WIDTH < HEIGHT)
		window_size = WIDTH;
	else
		window_size = HEIGHT;
	padding = window_size * 0.2;
	new_tile_size = (window_size - padding) / max_map_size;
	if (new_tile_size < env->tile_size)
		env->tile_size = new_tile_size;
	if (env->tile_size < 1)
		env->tile_size = 1;
}

// Fonction pour centrer la carte
void	center_map(t_env *env)
{
	double	scale_x;
	double	scale_y;

	scale_x = (WIDTH * SCALE) / (env->x_max - env->x_min);
	scale_y = (HEIGHT * SCALE) / (env->y_max - env->y_min);
	env->scale = fmin(scale_x, scale_y);
	env->x_center = (env->x_min + env->x_max) / 2.0;
	env->y_center = (env->y_min + env->y_max) / 2.0;
	env->x_center_offset = WIDTH / 2 - env->x_center * env->scale;
	env->y_center_offset = HEIGHT / 2 - env->y_center * env->scale;
}

void apply_center(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			env->points[y][x].x = (env->points[y][x].x - env->x_center)
				* env->scale + WIDTH / 2 + env->x_offset;
			env->points[y][x].y = (env->points[y][x].y - env->y_center)
				* env->scale + HEIGHT / 2 + env->y_offset;
			x++;
		}
		y++;
	}
}

void apply_projection(t_env *env)
{
	int	y;
	int	x;
	int	original_z;

	env->x_min = 0;
	env->x_max = 0;
	env->y_min = 0;
	env->y_max = 0;
	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			original_z = env->points[y][x].z;
			env->points[y][x].x = x * env->tile_size;
			env->points[y][x].y = y * env->tile_size;
			change_projection(&env->points[y][x], env);
			env->points[y][x].z = original_z;
			update_map_limits(env, x, y);
			x++;
		}
		y++;
	}
}

void update_map_limits(t_env *env, int x, int y)
{
	if (env->points[y][x].x < env->x_min)
		env->x_min = env->points[y][x].x;
	if (env->points[y][x].x > env->x_max)
		env->x_max = env->points[y][x].x;
	if (env->points[y][x].y < env->y_min)
		env->y_min = env->points[y][x].y;
	if (env->points[y][x].y > env->y_max)
		env->y_max = env->points[y][x].y;
}
