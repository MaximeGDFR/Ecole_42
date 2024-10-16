#include <unistd.h>
#include <stdio.h>

int	ft_isalnum(int c)
{
	if (c == '\0')
		return (0);
	if (c >= '0' && c <= '9'
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int c = ' ';
	int	result;

	result = ft_isalnum(c);
	printf("%d\n", result);
	return (0);
}*/