/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:49 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 21:50:27 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	count_digits(int n)
{
	int	len;

	len = 1;
	while ((n / 10) != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	write_sign(int n, int is_unsigned)
{
	if (n < 0 && !is_unsigned)
		return (write(1, "-", 1));
	return (0);
}

int	print_number(int n, t_flags *flags, int is_unsigned)
{
	int	count;
	int	num_len;
	int	spaces;
	int	zeros;

	num_len = count_digits(ft_abs(n));
	spaces = flags->width - num_len;
	zeros = flags->dot - num_len;
	count = 0;

	count += write_sign(n, is_unsigned);
	if (flags->dot > num_len)
		spaces = flags->width - flags->dot;
	if (spaces > 0 && !flags->zero)
		count = handle_padding(count, spaces, ' ');
	if (zeros > 0)
		count = handle_padding(count, zeros, '0');
	if (spaces > 0 && flags->zero)
		count = handle_padding(count, spaces, '0');
	if (n >= 10 || n <= -10)
		count += print_number(ft_abs(n / 10), flags, is_unsigned);
	count += ft_putchar((ft_abs(n % 10)) + '0');
	return (count);
}

int	ft_putnbr(int nb, int is_unsigned, t_flags *flags)
{
	return (print_number(nb, flags, is_unsigned));
}
