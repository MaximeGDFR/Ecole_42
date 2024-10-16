#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	i;
	unsigned int	j;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size <= dest_size)
		return (size + dest_size);
	i = dest_size;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_size + src_size);
}

/*int main()
{
    char dest [] = "Hello";
    char src [] = "world";
    unsigned int    size;
    unsigned int    result;

    size = 3;
    printf("Dest : %s\nSrc : %s\nSize : %d\n", dest, src, size);
    result = ft_strlcat(dest, src, size);
    printf("Size total : %d", result);
    return (0);
}*/