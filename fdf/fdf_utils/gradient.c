/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:25:29 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/08 02:37:41 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	active_gradient(t_data *data)
{
	data->colors->use_gradient = !data->colors->use_gradient;
}

int calculate_gradient(t_point p1, t_point p2, int current_step, int total_steps)
{
    int r1, g1, b1, r2, g2, b2;
    int r, g, b;

    // Extraire les composants RGB des couleurs des points
    r1 = (p1.color >> 16) & 0xFF;
    g1 = (p1.color >> 8) & 0xFF;
    b1 = p1.color & 0xFF;

    r2 = (p2.color >> 16) & 0xFF;
    g2 = (p2.color >> 8) & 0xFF;
    b2 = p2.color & 0xFF;

    // Calculer les couleurs intermédiaires en fonction de la progression
    r = r1 + (r2 - r1) * current_step / total_steps;
    g = g1 + (g2 - g1) * current_step / total_steps;
    b = b1 + (b2 - b1) * current_step / total_steps;

    // Combiner les composants RGB en une seule couleur
    return (r << 16) | (g << 8) | b;
}
