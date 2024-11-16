/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:09:00 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/16 23:20:47 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_long_as_hex(long unsigned addr)
{
	char	c;
	int		count;

	count = 0;
	if (addr >= 16)
		count += print_long_as_hex(addr / 16);
	c = (addr % 16) + '0';
	if ((addr % 16) > 9)
		c = ((addr % 16) + 87);
	write(1, &c, 1);
	return (count + 1);
}

static int	get_hex_size(long unsigned addr)
{
	int	count;

	count = 0;
	if (addr == 0)
		return (1);
	if (addr >= 16)
	{
		count += get_hex_size(addr / 16) + 1;
	}
	else
		count++;
	return (count);
}

int	ft_print_ptr(void *ptr, t_flags *flags)
{
	long	addr;
	int		count;
	int		len;

	count = 0;
	if (ptr == NULL)
	{
		len = 5;
		while (len + count < flags->min_width)
			count += print_char(' ');
		count += print_str("0x0");
		while (count < flags->offset)
			count += print_char(' ');
		return (count);
	}
	addr = (long unsigned)ptr;
	len = get_hex_size(addr) + 2;
	while (len + count < flags->min_width)
		count += print_char(' ');
	count += print_str("0x");
	count += print_long_as_hex(addr);
	while (count < flags->offset)
		count += print_char(' ');
	return (count);
}
