/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:59:58 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/06 14:45:23 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		handle_error("No map to free.\n", 1);
	i = 0;
	while (i < map->height)
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
	free(map);
}

int	close_window(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

t_map	*load_map(char *filename)
{
	t_map	*map;

	check_file_format(filename);
	map = init_map(filename);
	fill_matrix(filename, map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		handle_error("Error: argument number invalid.\n", 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		handle_error("Error: mlx_init failed.\n", 1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT,
			"FDF PROJECT - SCHOOL 42");
	if (!data.win)
		handle_error("Error: mlx_new_window failed.\n", 1);
	data.map = load_map(argv[1]);
	printf("Initial view : %d\n", data.map->current_view);
	draw_map(&data, data.map);
	mlx_hook(data.win, 2, 1L << 0, handle_controls, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
