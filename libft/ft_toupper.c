#include <stdio.h>
#include <unistd.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

/*int main()
{
    int c = 'b';
    int result;

    result = ft_toupper(c);
    printf("%c\n", result);
    return (0);
}*/