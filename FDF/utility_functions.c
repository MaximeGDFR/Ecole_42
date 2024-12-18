/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:57:16 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/18 12:00:05 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_format(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (i < 4 || filename[i - 1] != 'f' || filename[i - 2] != 'd'
		|| filename[i - 3] != 'f' || filename[i - 4] != '.')
	{
		handle_error("Error : Invalid file format.\n", 1);
	}
	return (TRUE);
}

int	get_sign(int value)
{
	if (value < 0)
		return (-1);
	else
		return (1);
}

int	get_position(t_menu *menu, int line_num)
{
	return (menu->pad_y + (line_num * LINE_HEIGHT));
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	free_values(char **values)
{
	int	i;

	i = 0;
	if (!values)
		return ;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}
