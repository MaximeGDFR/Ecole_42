/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:56:47 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 16:01:43 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_length(unsigned long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 16;
		length++;
	}
	return (length);
}

int	unsigned_int_length(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int	hexa_length(unsigned int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 16;
		length++;
	}
	return (length);
}
