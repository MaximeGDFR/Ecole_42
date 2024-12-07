/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classics_views_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:31:34 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 15:09:35 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_front(t_point *point, t_map *map)
{
	if (point == NULL || map == NULL)
		handle_error("Error: point or map is NULL in project_front.\n", 1);
	point->x = point->x;
	point->y = point->y - point->z;
}

void	projection_back(t_point *point, t_map *map)
{

	if (point == NULL || map == NULL)
		handle_error("Error: point or map is NULL in project_back.\n", 1);
	point->x = (map->width - 1 - point->x);
	point->y = point->y + point->z;
}
