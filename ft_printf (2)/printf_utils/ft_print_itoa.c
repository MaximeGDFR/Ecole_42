/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:39:29 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 17:51:40 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	itoa_length(long num)
{
	size_t	length;

	length = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		length++;
	}
	while (num >= 1)
	{
		num /= 10;
		length++;
	}
	return (length);
}

static char	*num_to_str(long num, char*str, size_t length)
{
	str = ft_calloc(length + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	length--;
	while (length)
	{
		str[length] = (num % 10) + '0';
		num /= 10;
		length--;
	}
	if (str[0] != '-')
		str[0] = (num % 10) + '0';
	return (str);
}

char	*print_itoa(long num)
{
	size_t	length;
	char	*str;

	length = itoa_length(num);
	str = 0;
	str = num_to_str(num, str, length);
	if (str == NULL)
		return (NULL);
	return (str);
}
