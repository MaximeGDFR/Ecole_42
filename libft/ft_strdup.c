#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strdup(const char *s)
{
    int i;
    int size;
    char *dup;

    i = 0;
    size = ft_strlen((char *)s) + 1;
    dup = (char *)malloc(size * sizeof(char));

    if (dup == NULL)
        return (NULL);

    while (i < size)
    {
        dup[i] = s[i];
        i++;
    }

    return (dup);
}

int main()
{
    char s [] = "Hello world !";
    char *result;

    result = ft_strdup(s);
    printf("Src : %s\n", s);
    printf("Copy : %s\n", result);
    free(result);
    return (0);
}