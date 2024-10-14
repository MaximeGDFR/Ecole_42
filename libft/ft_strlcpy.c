#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

/*int	main(void)
{
	char src [] = "Hello world !";
	char dest [10];
	unsigned int size = 10;

	printf("Src : %s\n", src);
	printf("Size src : 14\n");
	ft_strlcpy(dest, src, size);
	printf("Dest : %s\n", dest);
	printf("Size dest : %d\n", size);
	return (0);
}*/
