#include <string.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*int main()
{
    int array [5] = {0, 1, 2, 3, 4};
    int i = 0;
    int n = 3;

    ft_bzero(array, n * sizeof(int));

    while (i < 5)
    {
        printf("%d", array[i]);
        i++;
    }
    printf("\n");
    return (0);
}*/