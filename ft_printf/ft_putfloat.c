/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:53:29 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 16:25:41 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_before_dot(double nb)
{
	int	*len;
	int	int_part;

	int_part = (int)nb;
	if (int_part == 0)
		return (1);
	while (int_part != 0)
	{
		int_part /= 10;
		len++;
	}
	return (len);
}

int	before_dot(int int_part, t_flags *flags)
{
	int	count;

	count = 0;
	count += print_number(int_part, flags, 0);
	return (count);
}

int	after_dot(double nb, int precision, t_flags *flags)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (precision == 0)
		return (count);
	count += ft_putchar('.');
	nb -+ (int)nb;
	while (i < precision)
	{
		nb *= 10;
		count += ft_putchar((int)nb + '0');
		nb -= (int)nb;
		i++;
	}
	return (count);
}

int	ft_putfloat(double nb, t_flags *flags)
{
	int	count;
	int	num_len;
	int	spaces;
	int	zeros;
	int	int_part;

	count = 0;
	num_len = len_before_dot(nb);
	spaces = flags->width - num_len;
	zeros = flags->dot - num_len;
	if (spaces > 0 && flags->zero == 0)
		count = put_padding(count, spaces, ' ');
	if (zeros > 0)
		count = put_padding(count, zeros, '0');
	if (spaces > 0 && flags->zero == 1)
		count = put_padding(count, spaces, '0');
	int_part = (int)nb;
	count += before_dot(int_part, flags);
	count += after_dot(nb, flags->dot, flags);
	return (count);
}
