/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:57 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 21:51:13 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_addr_p(unsigned long addr, char *buf, int len)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (addr == 0)
		buf[len++] = '0';
	else
	{
		while (addr > 0)
		{
			buf[len++] = hex_digits[addr & 0xF];
			addr >>= 4;
		}
	}
	reorder_addr(buf, len);
	buf[len] = '\0';
	return (len);
}

int	ft_putaddr(void *ptr, t_flags *flags)
{
	unsigned long	addr;
	int				count;
	int				len;
	int				spaces;
	char			buffer[18];

	addr = (unsigned long)ptr;
	count = 0;
	buffer[0] = '0';
	buffer[1] = 'x';
	if (ptr == NULL)
	{
		buffer[2] = '0';
		len = 3;
	}
	else
		len = write_addr_p(addr, buffer, 2);
	spaces = flags->width - len;
	if (spaces > 0 && !flags->minus && !flags->zero)
		count += handle_padding(count, spaces, 0);
	if (spaces > 0 && flags->zero && !flags->minus)
		count += handle_padding(count, spaces, 1);
	count += write(1, buffer, len);
	if (spaces > 0 && flags->minus)
		count += handle_padding(count, spaces, 0);
	return (count);
}
