#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int ft_total_len(int size, char **strs, char *sep)
{
    int i;
    int total_len;
    int sep_len;

    total_len = 0;
    sep_len = ft_strlen(sep);
    i = 0;
    while (i < size)
    {
        total_len += ft_strlen(strs[i]);
        i++;
    }

    total_len += sep_len * (size - 1);

    return (total_len);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    char * empty_str;
    int total_len;
    char *result;
    int i;
    int j;
    int k;

    if (size == 0)
    {
        empty_str = (char *)malloc(1);
        if(empty_str == NULL)
            return (NULL);
        empty_str[0] = '\0';
        return (empty_str);
    }

    total_len = ft_total_len(size, strs, sep);
    i = 0;
    result = (char *)malloc((total_len + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);

    k = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j] != '\0')
        {
            result[k] = strs[i][j];
            k++;
            j++;
        }
        if (i < size - 1)
        {
            j = 0;
            while (sep[j] != '\0')
            {
                result[k] = sep[j];
                k++;
                j++;
            }
        }
        i++;
    }
    result[k] = '\0';
    return (result);
}

/*int main()
{
    char *strs [] = {"Hello", "world", "!"};
    char *sep = " ";
    int size = 3;

    char *result = ft_strjoin(size, strs, sep);
    if (result != NULL)
    {
        printf("Result : %s\n", result);
        free(result);
    }

    return (0);
}*/