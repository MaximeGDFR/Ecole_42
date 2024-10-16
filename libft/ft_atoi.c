#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;
	int	result;

	i = 0;
	sign = 1;
	value = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] <= 9 && str[i] >= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = str[i] - '0';
		result = result * 10 + value;
		i++;
	}
	return (result * sign);
}

/*int main()
{
    char str[] = "---+--+123456789abc567";

    printf("%d\n", ft_atoi(str));
    return (0);
}*/