/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:12:34 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 21:51:39 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reorder_addr(char *addr, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 2;
	end = len - 1;
	while (start < end)
	{
		temp = addr[start];
		addr[start] = addr[end];
		addr[end] = temp;
		start++;
		end--;
	}
	return (addr);
}

int	write_addr_x(unsigned long addr, char *buf, int len, t_flags *flags)
{
	char	*hex_digits;

	if (addr == 0)
		buf[len++] = '0';
	if (flags->is_upper == 1)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	while (addr > 0)
	{
		buf[len++] = hex_digits[addr & 0xF];
		addr >>= 4;
	}
	buf[len] = '\0';
	reorder_addr(buf, len);
	return (len);
}

int	ft_puthex(void *ptr, t_flags *flags)
{
	unsigned long	addr;
	int				count;
	int				len;
	int				spaces;
	char			buffer[19];

	if (ptr == NULL)
		return (write(1, "0x0", 3), 3);
	addr = (unsigned long)ptr;
	count = 0;
	buffer[0] = '0';
	buffer[1] = 'x';
	len = 2;
	count += write_addr_x(addr, buffer, len, flags);
	spaces = flags->width - count;
	if (spaces > 0 && !flags->zero)
		count = handle_padding(count, spaces, 0);
	count += write(1, buffer, count - 2);
	if (spaces > 0 && flags->zero)
		count = handle_padding(count, spaces, 1);
	return (count);
}
