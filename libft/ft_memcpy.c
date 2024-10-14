#include <stdio.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    char *d;
    const char *s;

    i = 0;
    d = (char *)dest;
    s = (const char *)src;
    //Cast en char* pour copier octet par octet directement dans la boucle

    while (i < n)
    {
        d[i] = s[i];
        i++;
    }

    return (dest);
}

/*int main()
{
    char dest [20];
    char src [] = "Hello world !";
    size_t n = 5;

    printf("%s\n", memcpy(dest, src, n));
    printf("%s\n", ft_memcpy(dest, src, n));

    return (0);
}*/