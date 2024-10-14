#include <unistd.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
        return (1);
	else
		return (0);
}

/*int	main(void)
{
	int c = ' ';
	int	result;

	result = ft_isprint(c);
	printf("%d\n", result);
	return (0);
}*/