/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:19:48 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 00:40:15 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_env env;

    if (argc != 2)
		handle_error("Error: argument number invalid.\n", 1);
    init_program(&env);

    env.height = get_height(argv[1]);
    env.width = get_width(argv[1]);
    allocate_matrix(&env);
    fill_matrix(argv[1], &env);

    calculate_scale(&env);
	apply_projection(&env);
    center_map(&env);
	apply_center(&env);
    draw_map(&env);
    mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
    mlx_hook(env.win_ptr, 17, 0L, close_window, &env);
    mlx_loop(env.mlx_ptr);

    free_points(&env);
    return (0);
}
