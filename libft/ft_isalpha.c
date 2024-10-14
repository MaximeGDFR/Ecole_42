#include <unistd.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if (c == '\0')
		return (0);
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return (1);
    else
        return (0);
}

/*int	main(void)
{
	int c = '\0';
	int	result;

	result = ft_isalpha(c);
	printf("%d\n", result);
	return (0);
}*/