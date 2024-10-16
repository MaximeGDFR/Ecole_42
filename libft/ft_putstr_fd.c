#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*int main()
{
    char s [] = "Hello world !";

    ft_putstr_fd(s, 1);
}*/