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

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int i;
    unsigned int j;
    int len_s;
    char *sub;

    i = 0;
    j = 0;
    len_s = ft_strlen(s);
    sub = (char *)malloc((len + 1) * sizeof(char));
    if (sub == NULL)
        return (NULL);

    if (start >= len_s)
    {
        sub[0] = '\0';
        return (sub);
    }
    
    i = start;
    while (i < start + len && s[i] != '\0')
    {
        sub[j] = s[i];
        j++;
        i++;
    }
    sub[j] = '\0';
    return (sub);
}

/*int main()
{
    char const s [] = "Hello world !";
    unsigned int start = 2;
    size_t len = 5;
    char *result;

    result = ft_substr(s, start, len);
    printf("Src : %s\nSub : %s\n", s, result);
    free(result);
    return (0);
}*/