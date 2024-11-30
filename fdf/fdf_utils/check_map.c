/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:31:51 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/29 17:55:29 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_digit(int i)
{
	if (i >= '0' && i <= '9')
		return (TRUE);
	else
		return (FALSE);
}

int	is_valid_format(const char *line)
{
	int	i;

	i = 0;
	if (line[i] == '-' || line[i] == '+')
		i++;
	if (!is_digit(line[i]))
		return (FALSE);
	while (is_digit(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n' || line[i] == ' ')
		return (TRUE);
	else
		return (FALSE);
}

int	check_line(const char *line)
{
	int	i;
	int	columns;

	i = 0;
	columns = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ' ')
		{
			i++;
			if (line[i] == ' ')
				return (FALSE);
			continue ;
		}
		if (!is_valid_format(&line[i]))
			return (FALSE);
		columns++;
		while (is_digit(line[i]) || line[i] == '-' || line[i] == '+')
			i++;
	}
	if (i > 0 && line[i - 1] == ' ')
		return (FALSE);
	return (columns);
}

int	handle_error(int fd, const char *error_msg)
{
	close (fd);
	write (1, error_msg, ft_strlen(error_msg));
	return (FALSE);
}

int	check_map(const char *filename)
{
	int		fd;
	char	*line;
	int		expected_columns;
	int		current_columns;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write (1, "Error opening file.\n", 21);
		return (FALSE);
	}
	expected_columns = -1;
	while ((line = get_next_line(fd)))
	{
		current_columns = check_line(line);
		free(line);
		if (current_columns == FALSE)
			return (handle_error(fd, "Error: Line format is invalid.\n"));
		if (expected_columns == -1)
			expected_columns = current_columns;
		else if (current_columns != expected_columns)
			return (handle_error(fd, "Error: Map is not rectangular.\n"));
	}
	close(fd);
	return (TRUE);
}
