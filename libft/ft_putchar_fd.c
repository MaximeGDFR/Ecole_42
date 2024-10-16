#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int main()
{
    ft_putchar_fd('A', 1);
    return (0);
}*/