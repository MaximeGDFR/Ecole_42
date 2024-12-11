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
void	check_open_file(int fd, char *filename)
{
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error opening file.\n", 1);
}
