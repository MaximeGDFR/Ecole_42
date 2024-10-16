#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int main()
{
    char array [10] = "abcdefghi";
    int i = 0;
    int n = 3;
    int c = 'X';

    ft_memset(array, c, n * sizeof(char));

    while (i < 10)
    {
        printf("%c", array[i]);
        i++;
    }
    printf("\n");

    return (0);
}*/