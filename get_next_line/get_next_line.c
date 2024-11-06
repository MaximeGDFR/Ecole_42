/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:51:17 by j                 #+#    #+#             */
/*   Updated: 2024/11/05 19:44:09 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	*ft_add_to_stash(char *stash, const char *readed)
{
	char	*new_stash;

	if (!readed)
		return (stash);
	if (!stash)
		return (ft_strdup(readed));
	new_stash = ft_strjoin(stash, readed);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (new_stash);
}

int	ft_line_finded(char *stash)
{
	int	i;

	if (!stash)
		return (-1);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_extract_line(char **stash)
{
	int		newline_pos;
	char	*line;
	char	*temp;

	if (!*stash || !**stash)
		return (NULL);
	newline_pos = ft_line_finded(*stash);
	if (newline_pos >= 0)
	{
		line = ft_substr(*stash, 0, newline_pos + 1);
		temp = ft_strdup(*stash + newline_pos + 1);
	}
	else
	{
		line = ft_strdup(*stash);
		temp = NULL;
	}
	free(*stash);
	*stash = temp;
	return (line);
}

char	*ft_read_and_stash(int fd, char **stash)
{
	char	readed[BUFFER_SIZE + 1];
	int		position;

	position = 0;
	while (1)
	{
		if (!ft_strchr(stash, '\n'))  // Si pas de \n trouvé
		{
			position = read(fd, readed, BUFFER_SIZE);
			if (position < 0)  // En cas d'erreur de lecture
			{
				free(*stash);
				*stash = NULL;  // Réinitialisez stash
				return (NULL);
			}
			if (position == 0)  // Fin de fichier
			{
				if (*stash && **stash)  // Si stash n'est pas vide
					return (ft_extract_line(stash));
				free(*stash);  // Libérer stash à la fin
				*stash = NULL;  // Réinitialiser stash
				return (NULL);  // Renvoie NULL pour EOF
			}
			readed[position] = '\0';  // Assurez-vous que buffer est terminé
			*stash = ft_add_to_stash(*stash, readed);
			if (!*stash)  // Vérifiez les erreurs d'allocation
				return (NULL);
		}
		else
			break;  // Si un \n est trouvé, sortir de la boucle
	}
	return (ft_extract_line(stash));
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_read_and_stash(fd, &stash))
		return (NULL);
	return (ft_extract_line(&stash));
}
