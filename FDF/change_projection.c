/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:40:43 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/16 21:41:28 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	change_projection(t_point *point, t_env *env)
{
	if (env->map->current_view < 1 || env->map->current_view > 7)
		env->map->current_view = 1;
	if (env->map->current_view == FRONT_VIEW)
		projection_front(point, env);
	else if (env->map->current_view == TOP_VIEW)
		projection_top(point, env);
	else if (env->map->current_view == RIGHT_VIEW)
		projection_right(point, env);
	else if (env->map->current_view == LEFT_VIEW)
		projection_left(point, env);
	else if (env->map->current_view == ISO_VIEW)
		projection_iso(point, env);
	else if (env->map->current_view == PERSPECTIVE_VIEW)
		projection_perspective(point, 1000);
	else if (env->map->current_view == OBLIQUE_VIEW)
		projection_oblique(point, 30.0, OBLIQUE_REDUCTION);
}

t_point	**allocate_projected_points(t_env *env)
{
	int		y;
	t_point	**projected_points;

	if (env->map->height <= 0 || env->map->width <= 0)
		handle_error("Invalid map dimensions in allocate_projected_points.\n", 1);

	projected_points = malloc(env->map->height * sizeof(t_point *));
	if (!projected_points)
		handle_error("Error allocation in apply_projection.\n", 1);
	y = -1;
	while (++y < env->map->height)
	{
		projected_points[y] = malloc(env->map->width * sizeof(t_point));
		if (!projected_points[y])
		{
			while (--y >= 0)
				free(projected_points[y]);
			free(projected_points);
			handle_error("In allocate_projected_points: error allocation for row.\n", 1);
			return (NULL);
		}
	}
	return (projected_points);
}

t_point	**apply_projection(t_env *env)
{
	int		y;
	int		x;
	t_point	**projected_points;

	projected_points = allocate_projected_points(env);
	if (!projected_points)
		handle_error("In apply_projection: error allocation for projected_points.\n", 1);
	
	printf("Allocating projected points for map of size: %dx%d\n", env->map->width, env->map->height);

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (++x < env->map->width)
		{
			printf("Applying projection to point: (x, y) = (%d, %d)\n", x, y);
			if (y < env->map->height && x < env->map->width)
			{
				projected_points[y][x] = projection(x, y, env);
				printf("Projected point: (x, y, z) = (%d, %d, %d)\n", projected_points[y][x].x, projected_points[y][x].y, projected_points[y][x].z);
			}
			x++;
		}
		y++;
	}
	return (projected_points);
}

void	free_projected_points(t_point **projected_points, int height)
{
	int	y;

	if (!projected_points)
		return ;
	y = 0;
	while (y < height)
	{
		if (projected_points[y])
			free(projected_points[y]);
		y++;
	}
	free(projected_points);
	projected_points = NULL;
}
*/