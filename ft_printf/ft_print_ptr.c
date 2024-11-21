/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:09:00 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/19 18:21:06 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_hex_digit(unsigned int digit, int is_upper)
{
    char c;

    if (digit < 10)
        c = digit + '0';
    else
    {
        if (is_upper)
            c = (digit - 10) + 'A';
        else
            c = (digit - 10) + 'a';
    }
    return (print_char(c));
}

int print_hex_number(unsigned long num, int is_upper)
{
    int count;

    count = 0;
    if (num == 0)
        return (print_char('0'));
    if (num >= 16)
        count += print_hex_number(num / 16, is_upper);
    count += print_hex_digit(num % 16, is_upper);
    return (count);
}



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

static int	get_hex_size(long unsigned addr)
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
}

int ft_print_ptr(void *ptr, t_flags *flags)
{
    int count = 0;
    unsigned long addr = (unsigned long)ptr;
    int len = 2 + get_hex_size(addr);  // "0x" + hex digits

    if (!flags->minus)
        count += print_padding(count, flags->min_width - len, ' ');

    count += print_str("0x");
    count += print_hex_number(addr, 0);  // 0 for lowercase

    if (flags->minus)
        count += print_padding(count, flags->min_width - count, ' ');

    return count;
}
