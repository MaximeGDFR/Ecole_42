/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:00:12 by j                 #+#    #+#             */
/*   Updated: 2024/10/30 17:51:51 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

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
	size_t	len;

	if (!*stash || !**stash)
		return (NULL);

	len = 0;
	while ((*stash)[len] && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\n')
		len++;
	line = ft_substr(*stash, 0, len);
	if (!line)
		return (NULL);
	if ((*stash)[len])
	{
		temp = ft_strdup(*stash + len);
		free(*stash);
		*stash = temp;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		readed[BUFFER_SIZE + 1];
	int			position;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	printf("--- Start of get_next_line ---\n");
	if (stash)
		printf("Initial stash: %s\n", stash);
	else
		printf("NULL");

	while (!stash || !ft_strchr(stash, '\n'))
	{
		position = read(fd, readed, BUFFER_SIZE);
		printf("Read %d bytes\n", position);
		if (position <= 0)
			break ;
		readed[position] = '\0';
		printf("Read content: %s\n", readed);
		stash = ft_add_to_stash(stash, readed);
		printf("Stash after add: %s\n", stash);
		if (!stash)
			return (NULL);
	}

	if (position < 0 || (position == 0 && !stash))
	{
		printf("End of file or error\n");
		return (NULL);
	}

	line = ft_extract_line(&stash);
	printf("Extracted line: %s\n", line);
	if (stash)
		printf("Remaining stash: %s\n", stash);
	else
		printf("NULL");
	printf("--- End of get_next_line ---\n\n");

	return (line);
}


int	main(void)
{
	int		fd;
	char	*line = NULL;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}
