/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:46:52 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 17:51:42 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	utoa_length(long num)
{
	size_t	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		num /= 10;
		length++;
	}
	return (length);
}

static char	*unsigned_to_str(unsigned int num, char *str, size_t length)
{
	str = ft_calloc(length + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (length)
	{
		str[length] = (num % 10) + '0';
		num /= 10;
		length--;
	}
	str[0] = (num % 10) + '0';
	return (str);
}

char	*print_utoa(unsigned int num)
{
	size_t	length;
	char	*str;

	length = utoa_length(num);
	str = 0;
	str = unsigned_to_str(num, str, length);
	if (str == NULL)
		return (NULL);
	return (str);
}
