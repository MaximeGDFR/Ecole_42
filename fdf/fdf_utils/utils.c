/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:08:04 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 15:56:33 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_format(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (filename[i - 1] != 'f' || filename[i - 2] != 'd'
		|| filename[i - 3] != 'f' || filename[i - 4] != '.')
	{
		write(1, "Error: wrong file format.\n", 27);
		return (FALSE);
	}
	return (TRUE);
}

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
