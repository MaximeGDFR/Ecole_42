/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:59:58 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/30 15:39:13 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
	{
		write (1, "Error: mlx_init failed\n", 23);
		return (1);
	}
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (!mlx_win)
	{
		write (1, "Error: mlx_new_window failed\n", 26);
		return (1);
	}
	mlx_loop(mlx);
	return (0);
}