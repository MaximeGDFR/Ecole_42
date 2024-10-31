/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:00:12 by j                 #+#    #+#             */
/*   Updated: 2024/10/31 11:08:17 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

/* ft_add_to_stash : dupliquer le contenu du buffer de read() et le stocker */
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
	free(stash);
	return (new_stash);
}

/* ft_clear_stash : effacer ce qui a deja ete retourner */
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
	char	*line;
	char	*temp;
	char	*newline_pos;

	if (!*stash || !**stash)
		return (NULL);
	newline_pos = ft_strchr(*stash, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(*stash);
		*newline_pos = '\n';
		temp = ft_strdup(newline_pos + 1);
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

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		readed[BUFFER_SIZE + 1];
	int			position;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash && ft_strchr(stash, '\n'))
		return (ft_extract_line(&stash));
	while (1)
	{
		position = read(fd, readed, BUFFER_SIZE);
		if (position <= 0)
			break ;
		readed[position] = '\0';
		stash = ft_add_to_stash(stash, readed);
		if (!stash)
			return (NULL);
		if (ft_strchr(readed, '\n'))
			break ;
	}
	if (stash)
		return (ft_extract_line(&stash));
	return (NULL);
}

/*int main(void)
{
	int		fd;
	char	*line;
	char	input[2];

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
			printf("\nEntrée pour continuer");
			printf("\n'q' pour quitter.\n");
			fgets(input, sizeof(input), stdin);
			if (input[0] == 'q')
				break ;
		}
		else
		{
			printf("Fin du fichier ou erreur de lecture.\n");
			break ;
		}
	}
	close(fd);
	return (0);
}*/