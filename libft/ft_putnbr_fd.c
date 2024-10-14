#include <unistd.h>

void    ft_putnbr_fd(int nb, int fd)
{
    char    c;

    if (nb == -2147483648)
        write(fd, "-2147483648", 11);
    else
    {
        if (nb < 0)
        {
            write(fd, "-", 1);
            nb = -nb;
        }
        if (nb >= 10)
        {
            ft_putnbr_fd(nb / 10, fd);
            ft_putnbr_fd(nb % 10, fd);
        }
        if (nb < 10)
        {
            c = nb + '0';
            write(fd, &c, 1);
        }
    }
}

/*int main(void)
{
    ft_putnbr_fd(-2147483648, 1);
    write(1, "\n", 1);
    ft_putnbr_fd(0, 1);
    write(1, "\n", 1);
    ft_putnbr_fd(42, 1);
    write(1, "\n", 1);
    ft_putnbr_fd(2147483647, 1);
    write(1, "\n", 1);
}*/