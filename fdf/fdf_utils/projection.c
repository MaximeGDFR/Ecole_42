/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:34:40 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 16:18:43 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_top(t_point *point, t_map *map)
{
	if (point == NULL || map == NULL)
		handle_error("Error: point or map is NULL in project_top.\n", 1);
	point->x = point->x;
	point->y = point->y;
}

void	projection_under(t_point *point, t_map *map)
{
	if (point == NULL || map == NULL)
		handle_error("Error: point or map is NULL in project_under.\n", 1);
	point->x = point->x;
	point->y = map->height - point->y;
}

void	project_right(t_point *point, t_map *map)
{
	int	tmp;

	if (point == NULL || map == NULL)
		handle_error("Error: point or map is NULL in project_right.\n", 1);
	tmp = point->x;
	point->x = point->z;
	point->y = point->y;
	point->z = tmp;
}

void	project_left(t_point *point, t_map *map)
{
	int	tmp;

	if (point == NULL || map == NULL)
		handle_error("Error: point or map is NULL in project_left.\n", 1);
	tmp = point->x;
	point->x = map->width - point->z;
	point->y = point->y;
	point->z = tmp;
}

void	project_front(t_point *point, t_map *map)
{
	printf("Before projection: x: %d, y: %d\n", point->x, point->y);
	if (point == NULL || map == NULL)
		handle_error("Error: point or map is NULL in project_front.\n", 1);
	point->x = point->x;
	point->y = point->y - point->z;
	printf("After projection: x: %d, y: %d\n", point->x, point->y);
}
