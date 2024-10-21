/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:27:31 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/19 14:13:36 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	value;
	int	result;

	i = 0;
	sign = 1;
	value = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] <= 9 && nptr[i] >= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-' && nptr[i + 1] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = nptr[i] - '0';
		result = result * 10 + value;
		i++;
	}
	return (result * sign);
}

/*int main()
{
    char nptr[] = "-123456789abc567";

    printf("%d\n", ft_atoi(nptr));
    return (0);
}*/