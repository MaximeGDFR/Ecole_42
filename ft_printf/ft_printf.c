/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:47 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/12 20:12:57 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->precision = 0;
}

static int	check_type(const char *input, va_list args, t_flags *flags)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			check_flags(input, &i, flags);
			if (input[i] == '%')
				count += ft_putchar('%');
			else if (input[i] == 'd' || input[i] == 'i' || input[i] == 'u'
				|| input[i] == 'x' || input[i] == 'X' || input[i] == 'f')
				count += handle_numeric_types(input[i], args, flags);
			else if (input[i] == 'p')
				count += ft_putaddr(va_arg(args, void *));
			else if (input[i] == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (input[i] == 's')
				count += ft_putstr(va_arg(args, const char *));
		}
		else
			count += ft_putchar(input[i]);
		i++;
	}
	return (count);
}

static int	handle_numeric_types(char type, va_list args, t_flags *flags)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return (ft_putnbr(va_arg(args, int), flags));
	else if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg(args, unsigned int), type, flags));
	else if (type == 'f')
		return (ft_putfloat(va_arg(args, double), flags));
	return (0);
}

static int	check_precision(const char *input, int *index, t_flags *flags)
{
	if (input[*index] == '.')
	{
		(*index)++;
		flags->dot = 1;
		flags->precision = 0;
		if (input[*index] >= '0' && input[*index] <= '9')
		{
			while (input[*index] >= '0' && input[*index] <= '9')
			{
				flags->precision = flags->precision * 10
					+ (input[*index] - '0');
				(*index)++;
			}
		}
	}
	return (1);
}

static int	check_width(const char *input, int *index, t_flags *flags)
{
	if (input[*index] >= '0' && input[*index] <= '9')
	{
		flags->width = 0;
		while (input[*index] >= '0' && input[*index] <= '9')
		{
			flags->width = flags->width * 10
				+ (input[*index] - '0');
			(*index)++;
		}
	}
	return (1);
}

static int	check_flags(const char *input, int *index, t_flags *flags)
{
	while (input[*index] == '+' || input[*index] == '#'
		|| input[*index] == ' ' || input[*index] == '-'
		|| input[*index] == '0')
	{
		if (input[*index] == '+')
			flags->plus = 1;
		else if (input[*index] == '#')
			flags->hash = 1;
		else if (input[*index] == ' ')
			flags->space = 1;
		else if (input[*index] == '-')
			flags->minus = 1;
		else if (input[*index] == '0')
			flags->zero = 1;
		(*index)++;
	}
	check_width(input, index, flags);
	check_precision(input, index, flags);
	return (1);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	if (input == NULL)
		return (0);
	init_flags(&flags);
	va_start(args, input);
	count += check_type(input, args, &flags);
	va_end(args);
	return (count);
}