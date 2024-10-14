#include <stdio.h>
#include <unistd.h>
#include <string.h>

void    ft_putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(fd, &str[i], 1);
        i++;
    }
}

/*int main()
{
    char str [] = "Hello world !";

    ft_putstr_fd(str, 1);
}*/