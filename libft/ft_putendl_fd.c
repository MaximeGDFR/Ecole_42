#include <stdio.h>
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	else
	{
		while (s[i] != '\0')
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
	write (fd, "\n", 1);
	return (s);
}

/*int main()
{
    int fd = 1;
    char *message = "Hello, world!";
    
    ft_putendl_fd(message, fd);

    return (0);
}*/