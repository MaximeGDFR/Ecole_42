/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:25:28 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 19:14:18 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(char *nb_str, int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (flags.zero == 0 || flags.precision >= 0)
			count += print_char('-');
	}
	else if (flags.plus == 1 && flags.zero == 0)
		count += print_char('+');
	else if (flags.space == 1 && flags.zero == 0)
		count += print_char(' ');
	if (flags.precision >= 0)
		count += pad_width(flags.precision - 1, ft_strlen(nb_str) - 1, 1);
	count += print_string(nb_str);
	return (count);
}

int	print_sign(int n, t_flags *flags)
{
	int	count;

	count = 0;
	if (n < 0 && flags->precision == -1)
	{
		count += print_char('-');
		flags->width--;
	}
	else if (flags->plus == 1)
		count += print_char('+');
	else if (flags->space == 1)
	{
		count += print_char(' ');
		flags->width--;
	}
	return (count);
}

int	print_int(char *nb_str, int n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1)
		count += print_sign(n, &flags);
	if (flags.minus == 1)
		count += print_num(nb_str, n, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nb_str))
		flags.precision = ft_strlen(nb_str);
	if (flags.precision >= 0)
	{
		flags.width = flags.precision;
		if (n < 0 && flags.minus == 0)
			flags.width -= 1;
		count += pad_width(flags.width, 0, 0);
	}
	else
		count += pad_width(flags.width - flags.plus - flags.space,
				ft_strlen(nb_str), flags.zero);
	if (flags.minus == 0)
		count += print_num(nb_str, n, flags);
	return (count);
}

int	ft_print_number(int n, t_flags flags)
{
	char	*nb_str;
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb *= 1;
		if (flags.zero == 0)
			flags.width--;
	}
	if (flags.precision == 0 && n == 0)
	{
		count += pad_width(flags.width, 0, 0);
		return (count);
	}
	nb_str = print_itoa(nb);
	if (!nb_str)
		return (0);
	count += print_int(nb_str, n, flags);
	free(nb_str);
	return (count);
}
