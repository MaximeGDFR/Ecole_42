#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int ft_count_substring(char *s, char c)
{
    int count;
    int in_substring;
    int i;

    count = 0;
    in_substring = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] != c && !in_substring)
        {
            in_substring = 1;
            count++;
        }
        else if (s[i] == c)
        {
            in_substring = 0;
        }
        i++;
    }
    return (count);
}

static char *ft_strndup(const char *s, size_t n)
{
    char *dup;
    size_t i;

    dup = malloc(n + 1);
    if (dup == NULL)
        return (NULL);
    i = 0;
    while (i < n && s[i] != '\0')
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char **ft_split(char const *s, char c)
{
    char **result;
    int substring_count;
    int i;
    int start;
    int j;

    if (s == NULL)
        return (NULL);
    substring_count = ft_count_substring(s, c);
    result = malloc((substring_count + 1) * sizeof(char *));
    if (result == NULL)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        if (s[i] != c)
        {
            start = i;
            while (s[i] != '\0' && s[i] != c)
                i++;
            result[j] = ft_strndup(&s[start], i - start);
            j++;
        }
        else
            i++;
    }
    result[j] = NULL;
    return (result);
}

/*int	main()
{
	char	*str = "Hello,world,this,is,a,test";
	char	c = ',';
	char	**result;
	int		i;

	result = ft_split(str, c);
	for (i = 0; result[i] != NULL; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}*/