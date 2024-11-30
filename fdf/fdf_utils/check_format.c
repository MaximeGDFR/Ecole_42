/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:08:04 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/30 15:34:39 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function A = check format nom fichier (4 derniers caractères arg1)
Function B = check nombre d'arg (!= 2 -> error)
Function C = check format de la map (toutes les lignes égales aux mêmes formats)
*/

#include "fdf.h"

int	check_nb_arg(int ac)
{
	if (ac != 2)
	{
		write(1, "Error: wrong number of arguments.\n", 34);
		return (FALSE);
	}
	return (TRUE);
}

int	check_file_format(char *filename)
{
	int	i;

	i = ft_strlen(filename);
	if (filename[i] != 'f' || filename[i - 1] != 'd'
		|| filename[i - 2] != 'f' || filename[i - 3] != '.')
	{
		write(1, "Error: wrong file format.\n", 27);
		return (FALSE);
	}
	return (TRUE);
}
