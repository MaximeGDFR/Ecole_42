/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:52:23 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 17:57:14 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	xtoa_length(long num)
{
	size_t	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		num /= 16;
		length++;
	}
	return (length);
}

static char	*hex_to_str(unsigned long num, char *str, size_t length)
{
	int	mod;

	str = ft_calloc(length + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	length--;
	while (length != (size_t)-1)
	{
		mod = num % 16;
		if (mod < 10)
			str[length] = mod + '0';
		else if (mod >= 10)
			str[length] = (mod - 10) + 'a';
		num /= 16;
		length--;
	}
	return (str);
}

char	*print_xtoa(unsigned long num, int is_upper)
{
	size_t	length;
	char	*str;
	int		i;

	length = xtoa_length(num);
	str = 0;
	str = hex_to_str(num, str, length);
	if (str == NULL)
		return (NULL);
	if (is_upper == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}
