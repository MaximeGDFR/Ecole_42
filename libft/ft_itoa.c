#include <stdlib.h>
#include <stdio.h>

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	get_num_length(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*handle_zero_case(void)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		i;
	int		is_neg;
	char	*result;
	long	num;

	num = n;
	if (num == 0)
		return (handle_zero_case());
	is_neg = (num < 0);
	if (is_neg)
		num = -num;
	result = (char *)malloc((get_num_length(num) + is_neg + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (is_neg)
		result[i++] = '-';
	j = (get_num_length(num) + is_neg) - 1;
	while (num > 0)
	{
		result[j--] = (num % 10) + '0';
		num /= 10;
	}
	result[get_num_length(num) + is_neg] = '\0';
	return (result);
}

/*int main()
{
    char *str;

    str = ft_itoa(1234);
    printf("1234 : %s\n", str);
    free(str);

    str = ft_itoa(-42);
    printf("-42 : %s\n", str);
    free(str);

    str = ft_itoa(2123456789);
    printf("2123456789 : %s\n", str);
    free(str);

    return (0);
}*/