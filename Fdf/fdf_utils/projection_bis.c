/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:35:40 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/10 23:30:50 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_back(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_back.\n", 1);
	point->x = (env->width - 1 - point->x);
	point->y = point->y + point->z;
}

void projection_iso(t_point *point, t_env *env)
{
    int prev_x;

    if (point == NULL || env == NULL)
        handle_error("Error: point or env is NULL in projection_iso.\n", 1);
    
    // Projection isométrique simple
    prev_x = point->x;
    point->x = (point->x - point->y) * cos(M_PI / 6);
    point->y = (prev_x + point->y) * sin(M_PI / 6) - point->z;

    // Ajout d'un print pour voir les coordonnées après projection
    printf("After projection: x = %d, y = %d, z = %d\n", point->x, point->y, point->z);
}


void	projection_perspective(t_point *point, float d)
{
	if (d + point->z != 0)
	{
		point->x = point->x / (1 + point->z / d);
		point->y = point->y / (1 + point->z / d);
	}
}

void	projection_oblique(t_point *point, float angle, float reduction)
{
	float	rad;

	rad = angle * M_PI / 180.0;
	point->x = point->x + reduction * point->z * cos(rad);
	point->y = point->y + reduction * point->z * sin(rad);
}

void	projection_dimetric(t_point *point)
{
	float	cos45;
	float	sin45;
	float	cos30;
	float	sin30;
	int		tmp_x;

	cos45 = cos(M_PI / 4);
	sin45 = sin(M_PI / 4);
	cos30 = cos(M_PI / 6);
	sin30 = sin(M_PI / 6);
	tmp_x = point->x;
	point->x = tmp_x * cos45 - point->y * cos30;
	point->y = tmp_x * sin45 + point->y * sin30 - point->z;
}

void	projection_trimetric(t_point *point, float alpha,
			float beta, float gamma)
{
	float	rad_alpha;
	float	rad_beta;
	float	rad_gamma;
	int		new_x;
	int		new_y;

	rad_alpha = alpha * M_PI / 180.0;
	rad_beta = beta * M_PI / 180.0;
	rad_gamma = gamma * M_PI / 180.0;
	new_x = point->x * cos(rad_alpha) - point->y * cos(rad_beta);
	new_y = point->x * sin(rad_alpha) + point->y * sin(rad_beta)
		- point->z * cos(rad_gamma);
	point->x = new_x;
	point->y = new_y;
}

void	projection_top(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_top.\n", 1);
}

void	projection_under(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in projection_under.\n", 1);
	point->y = env->height - point->y;
}

void	project_right(t_point *point, t_env *env)
{
	int	tmp;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_right.\n", 1);
	tmp = point->x;
	point->x = point->z;
	point->z = tmp;
}

void	project_left(t_point *point, t_env *env)
{
	int	tmp;

	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_left.\n", 1);
	tmp = env->width - (point -> z);
	point -> x = tmp;
	point -> z = tmp;
}

void	project_front(t_point *point, t_env *env)
{
	if (point == NULL || env == NULL)
		handle_error("Error: point or env is NULL in project_front.\n", 1);
	point -> y -= (point -> z);
}

// Change la projection du point en fonction de la vue courante
void change_projection(t_point *point, t_env *env)
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

// Change la vue courante selon un ordre prédéfini
void change_view(t_env *env)
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
