/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:38:46 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 18:41:43 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_addr(unsigned long n)
{
	if (n > 16)
	{
		print_addr(n / 16);
		print_addr(n % 16);
	}
	else
	{
		if (n < 10)
			print_char(n + '0');
		else if (n >= 10)
			print_char((n - 10) + 'a');
	}
}

int	print_p(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += print_string(PTRNULL);
		return (count);
	}
	count += print_string("0x");
	print_addr(n);
	count += pointer_length(n);
	return (count);
}

int	ft_print_pointer(unsigned long n, t_flags flags)
{
	int	count;

	count = 0;
	if (n == 0)
		flags.width = ft_strlen(PTRNULL) - 1;
	else
		flags.width -= 2;
	if (flags.minus == 1)
		count += print_p(n);
	count += pad_width(flags.width, pointer_length(n), 0);
	if (flags.minus == 0)
		count += print_p(n);
	return (count);
}
