/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:09:46 by j                 #+#    #+#             */
/*   Updated: 2024/11/08 17:57:41 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*keep_rest(char *temp, int start_next)
{
	char	*rest;

	rest = ft_strdup(temp + start_next);
	free(temp);
	return (rest);
}

static char	*extract_line(char *temp, int *start_next)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	line = ft_substr(temp, 0, i);
	*start_next = i;
	return (line);
}




char	*new_line(int fd, char *buffer, char *temp)
{
	int		read_bytes;
	char	*new_temp;

	while (temp && !ft_strchr(temp, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temp);  // Libération en cas d'erreur
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		new_temp = ft_strjoin(temp, buffer);
		if (!new_temp)
		{
			free(temp);  // Libérer `temp` si `ft_strjoin` échoue
			return (NULL);
		}
		free(temp);
		temp = new_temp;
	}
	return (temp);
}

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    static char *temp;
    int start_next;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    
    if (!temp)
    {
        temp = ft_strdup("");  // Ensure temp is correctly allocated
        if (!temp)
            return (NULL);
    }

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);

    temp = new_line(fd, buffer, temp);
    free(buffer);  // Free buffer after use

    if (!temp || temp[0] == '\0')
        return (NULL);  // Return NULL if temp is empty (empty file)

    line = extract_line(temp, &start_next);
    if (!line)
    {
        free(temp);  // Free temp if line extraction fails
        return (NULL);
    }

    temp = keep_rest(temp, start_next);
    return (line);
}



