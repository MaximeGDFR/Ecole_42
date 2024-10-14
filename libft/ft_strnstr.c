#include <stdio.h>
#include <string.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if (needle[0] == '\0')
        return ((char *)haystack);
    while (haystack[i] != '\0' && i < len)
    {
        j = 0;
        while (haystack[i + j] == needle[j] && (i + j) < len)
        {
            if (needle[j + 1] == '\0')
                return (char *)&haystack[i];
            j++;
        }
        i++;
    }
    return (NULL);
}

/*int main ()
{
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    size_t len = 14;

    char *result = ft_strnstr(haystack, needle, len);

    if (result != NULL)
        printf("Finded needle : %s\n", result);
    else
        printf("No result in %d prints.", len);
    
    return (0);
}*/