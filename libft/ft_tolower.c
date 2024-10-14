#include <stdio.h>
#include <unistd.h>

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' - 'A'));
    else
        return (c);
}

int main()
{
    int c = 'A';
    int result;

    result = ft_tolower(c);
    printf("%c\n", result);
    return (0);
}