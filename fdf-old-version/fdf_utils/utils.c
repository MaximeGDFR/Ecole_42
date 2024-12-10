/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:08:04 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 15:27:53 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	free_values(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		values[i] = NULL;
		i++;
	}
	free(values);
	values = NULL;
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

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







