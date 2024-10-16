#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*int main()
{
    char s1 [] = "abcdef";
    char s2 [] = "abcdefghijkl";
    unsigned int n;

    n = 17;
    int result_a = ft_strncmp(s1, s2, n);
    int result_b = strncmp(s1, s2, n);

    printf("%d %d\n", result_a, result_b);
    return (0);
}*/