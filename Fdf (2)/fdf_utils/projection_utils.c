/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:50:11 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 15:32:26 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clip_point(t_point *point)
{
	float	margin;
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;

	margin = 0.1;
	max_x = WIDTH * (1 + margin);
	max_y = HEIGHT * (1 + margin);
	min_x = -WIDTH * margin;
	min_y = -HEIGHT * margin;
	point->x = fmax(min_x, fmin(point->x, max_x));
	point->y = fmax(min_y, fmin(point->y, max_y));
}

void	change_projection(t_point *point, t_env *env)
{
	if (env->current_view < 1 || env->current_view > 11)
		env->current_view = 1;
	if (env->current_view == FRONT_VIEW)
		project_front(point, env);
	else if (env->current_view == BACK_VIEW)
		projection_back(point, env);
	else if (env->current_view == TOP_VIEW)
		projection_top(point, env);
	else if (env->current_view == UNDER_VIEW)
		projection_under(point, env);
	else if (env->current_view == RIGHT_VIEW)
		project_right(point, env);
	else if (env->current_view == LEFT_VIEW)
		project_left(point, env);
	else if (env->current_view == ISO_VIEW)
		projection_iso(point, env);
	else if (env->current_view == PERSPECTIVE_VIEW)
		projection_perspective(point, 1000);
	else if (env->current_view == OBLIQUE_VIEW)
		projection_oblique(point, 30.0, OBLIQUE_REDUCTION);
	else if (env->current_view == DIMETRIC_VIEW)
		projection_dimetric(point);
	else if (env->current_view == TRIMETRIC_VIEW)
		projection_trimetric(point, 30.0, 45.0, 60.0);
}

void	change_view(t_env *env)
{
	if (env->current_view == 1)
		env->current_view = FRONT_VIEW;
	else if (env->current_view == 2)
		env->current_view = BACK_VIEW;
	else if (env->current_view == 3)
		env->current_view = TOP_VIEW;
	else if (env->current_view == 4)
		env->current_view = UNDER_VIEW;
	else if (env->current_view == 5)
		env->current_view = RIGHT_VIEW;
	else if (env->current_view == 6)
		env->current_view = LEFT_VIEW;
	else if (env->current_view == 7)
		env->current_view = ISO_VIEW;
	else if (env->current_view == 8)
		env->current_view = PERSPECTIVE_VIEW;
	else if (env->current_view == 9)
		env->current_view = OBLIQUE_VIEW;
	else if (env->current_view == 10)
		env->current_view = DIMETRIC_VIEW;
	else if (env->current_view == 11)
		env->current_view = TRIMETRIC_VIEW;
}

void	apply_projection(t_env *env)
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

void	project_left(t_point *point, t_env *env)
{
	int	tmp;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_left.\n", 1);
	tmp = env->width - (point -> z);
	point -> x = tmp;
	point -> z = tmp;
	clip_point(point);
}
