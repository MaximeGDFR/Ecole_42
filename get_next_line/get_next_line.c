/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:00:12 by j                 #+#    #+#             */
/*   Updated: 2024/10/30 16:10:21 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ft_add_to_stash sert a dupliquer le contenu du buffer de read() et le stocker */
char	*ft_add_to_stash(char *stash, const char *readed)
{
	char	*new_stash;

	if (!readed)
		return (stash);
	if (!stash)
		return (ft_strdup(readed));
	new_stash = ft_strjoin(stash, readed);
	if (!new_stash)
		return (NULL);
	if (!new_stash)
		return (NULL);
	free(stash);
	return (new_stash);
}

/* ft_clear_stash sert a effacer ce qui a deja ete retourner depuis la reserve de read() et ne garder que le restant */
char	*ft_clear_stash(char *stash, int i)
{
	int	j;
	int	len_stash;

	if (!stash)
		return (NULL);
	len_stash = ft_strlen(stash);
	if (i >= len_stash)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i + j])
	{
		stash[j] = stash[i + j];
		j++;
	}
	stash[j] = '\0';
	return (stash);
}

int	ft_line_finded(char *stash)
{
	int	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*readed;
	int				position;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	stash = read(fd, readed, BUFFER_SIZE);
	if (ft_line_finded(stash) == 0)
		ft_add_to_stash(stash, readed);
	else
	{
		ft_add_to_stash(stash, readed);
		line = stash;
		ft_clear_stash(stash, position);
	}
	return (line);
}
