/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:42:55 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 18:48:42 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(t_flags *flags)
{
	flags->spe = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->precision = -1;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	return (*flags);
}

t_flags	handle_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	handle_digits(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags	handle_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int	handle_precision(const char *str, int pos, va_list args, t_flags *flags)
{
	int	i;

	i = pos + 1;
	if (str[i] == '*')
	{
		flags->precision = va_arg(args, int);
		return (i++);
	}
	flags->precision = 0;
	while (is_digit(str[i]))
	{
		flags->precision = (flags->precision * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}
