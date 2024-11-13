/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:49 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 19:18:22 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_padding(int count, int spaces, int is_zero)
{
	char	fill_char;

	fill_char = ' ';
	if (is_zero)
		fill_char = '0';
	while (spaces > 0)
	{
		count += write(1, &fill_char, 1);
		spaces--;
	}
	return (count);
}

int	get_num_lenght(int nb, int is_unsigned)
{
	int					i;
	unsigned long long	un;

	i = 1;
	if (nb < 0 && !is_unsigned)
		un = -((unsigned long long)nb);
	else
		un = (unsigned long long)nb;
	while ((un / 10) > 0)
	{
		un /= 10;
		i++;
	}
	return (i);
}

int	is_negative(int count, int n, int is_unsigned)
{
	if (n < 0 && !is_unsigned)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	return (count);
}

int	print_number(long long n, t_flags *flags, int is_unsigned)
{
	int	count;
	int	num_len;
	int	spaces;
	int	zeros;

	count = 0;
	num_len = get_num_lenght(n);
	spaces = flags->width - num_len;
	zeros = flags->dot - num_len;
	count += is_negative(count, n, is_unsigned);
	if (flags->dot > num_len)
		spaces = flags->width - flags->dot;
	if (spaces > 0 && flags->zero == 0)
		count = put_padding(count, spaces, ' ');
	if (zeros > 0)
		count = put_padding(count, zeros, '0');
	if (spaces > 0 && flags->zero == 1)
		count = put_padding(count, spaces, '0');
	if (n >= 10)
		count += print_number(n / 10, flags, is_unsigned);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr(int n, int is_unsigned, t_flags *flags)
{
	return (print_number(n, flags, is_unsigned));
}
