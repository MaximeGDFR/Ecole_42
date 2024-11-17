/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:09:00 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/17 12:46:04 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_long_as_hex(unsigned long addr)
{
	int		count;
	char	c;

	count = 0;
	if (addr >= 16)
		count += print_long_as_hex(addr / 16);
	c = "0123456789abcdef"[addr % 16];
	write(1, &c, 1);
	return (count + 1);
}

/*static int	get_hex_size(long unsigned addr)
{
	int	count;

	if (addr == 0)
		return (1);
	count = 0;
	while (addr)
	{
		addr /= 16;
		count++;
	}
	return (count);
}*/

int	ft_print_ptr(void *ptr, t_flags *flags)
{
	int				count;
	unsigned long	addr;

	count = 0;
	addr = (unsigned long)ptr;
	if (ptr == NULL)
		count += print_str("(nil)");
	else
	{
		count += print_str("0x");
		count += print_long_as_hex(addr);
	}
	while (count < flags->min_width)
	{
		if (flags->zero)
			count += print_char('0');
		else
			count += print_char(' ');
	}
	return (count);
}
