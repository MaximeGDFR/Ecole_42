/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:49 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/12 19:08:27 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_unsigned(int n, t_flags *flags)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count += putnbr_unsigned(n / 10, flags);
		count += putnbr_unsigned(n % 10, flags);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		count++;
	}
	return (count);
}


int	putnbr_signed(int n, t_flags *flags)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += putnbr_signed(n / 10, flags);
	c = n % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr(int n, int is_unsigned, t_flags *flags)
{
	int	count;

	count = 0;
	if (is_unsigned == 0)
		count += putnbr_signed(n, flags);
	else
		count += putnbr_unsigned(n, flags);
	return (count);
}