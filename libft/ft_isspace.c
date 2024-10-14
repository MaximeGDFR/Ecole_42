#include <unistd.h>
#include <stdio.h>

int	ft_isspace(int c)
{
    if (c == EOF)
        return (0);
	if ((unsigned char)c >= 9 && (unsigned char)c <= 13
    || (unsigned char)c == 32)
        return (1);
	else
		return (0);
}

/*int	main(void)
{
	int c = ' ';
	int	result;

	result = ft_isspace(c);
	printf("%d\n", result);
	return (0);
}*/