/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:02:28 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 19:37:42 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_matrix(t_env *env)
{
	int	i;

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

void	fill_matrix(char *filename, t_env *env)
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
		if (y >= env->height)
			handle_error("Error: rows not matching height.\n", 1);
		fill_row(env, line, y);
		get_z_min_max(line, env);
		free(line);
		y++;
	}
	if (y != env->height)
		handle_error("Error: rows not matching height.\n", 1);
	if (close(fd) < 0)
		handle_error("Closing error.\n", 1);
}

void	fill_row(t_env *env, char *line, int y)
{
	char	**values;
	int		x;

	values = ft_split(line, ' ');
	if (!values)
		handle_error("Error: invalid format.\n", 1);
	x = 0;
	while (x < env->width)
	{
		env->points[y][x].x = x * env->tile_size;
		env->points[y][x].y = y * env->tile_size;
		env->points[y][x].z = ft_atoi(values[x]);
		env->points[y][x].color = calculate_color(env->points[y][x].z,
				env, env->color_mode);
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

#include <stdlib.h>

#define COLOR_MODE_GRADIENT 1
#define COLOR_MODE_CONSTANT 2

int calculate_color(int z, t_env *env, int color_mode)
{
	(void)env;
    int color;

    if (color_mode == COLOR_MODE_GRADIENT)
    {
        // Calcul simple d'une couleur en dégradé en fonction de z
        // Ici on applique une logique basique pour simuler un dégradé
        // Exemple : plus z est élevé, plus la couleur devient rouge (modèle RGB).
        color = (z < 0) ? 0x0000FF : 0xFF0000;  // Bleu pour les valeurs négatives, rouge pour les positives.
        // Tu peux rajouter des calculs plus complexes ici, par exemple en fonction des min/max de z.
    }
    else if (color_mode == COLOR_MODE_CONSTANT)
    {
        // Mode constant, toutes les couleurs seront égales
        color = 0xFFFFFF;  // Blanc
    }
    else
    {
        // Valeur par défaut en cas de mode de couleur inconnu
        color = 0x000000;  // Noir
    }

    return color;
}
