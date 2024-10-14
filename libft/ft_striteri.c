#include <stdio.h>
#include <stdlib.h>

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - ('a' - 'A'));
    else
        return (c);
}

void    my_function(unsigned int i, char *c)
{
    (void)i;
    *c = ft_toupper(*c); // Remplacer par la fonction voulue
}

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    i = 0;
    if (s && f)
    {
        while (s[i])
        {
            f(i, &s[i]);
            i++;
        }
    }
}

/*int main()
{
    char str [] = "Hello world !";
    ft_striteri(str, my_function);
    printf("%s\n", str);
    return (0);
}*/