#include <stdio.h>
#include <stdlib.h>

int ft_strchr(const char *set, char c)
{
    while (*set)
    {
        if (*set == c)
            return (1);
        set++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int start;
    int end;
    int i;
    char *trimmed;
    
    start = 0;
    while (s1[start] != '\0' && ft_strchr(set, s1[start]))
        start++;

    if (s1[start] == '\0')
        return (malloc(1));

    end = start;
    while (s1[end] != '\0')
        end++;
    
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
    
    trimmed = (char *)malloc((end - start + 1) * sizeof(char));
    if (trimmed == NULL)
        return (NULL);
    
    i = 0;
    while (start < end)
    {
        trimmed[i] = s1[start];
        i++;
        start++;
    }
    trimmed[i] = '\0';
    return (trimmed);
}

/*int main()
{
    char const *s1 = "   Hello World!   ";
    char const *set = " ";
    char *trimmed;

    trimmed = ft_strtrim(s1, set);

    if (trimmed == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return (1);
    }

    printf("Avant trim : '%s'\n", s1);
    printf("Après trim : '%s'\n", trimmed);

    free(trimmed);

    return (0);
}*/