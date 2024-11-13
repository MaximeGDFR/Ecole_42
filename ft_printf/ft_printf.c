/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:47 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 19:02:42 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			else if (input[i] == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (input[i] == 's')
				count += ft_putstr(va_arg(args, const char *));
			else
				count += handle_numeric_types(input[i], args, flags);
		}
		else
			count += ft_putchar(input[i]);
		i++;
	}
	return (count);
}

int	handle_numeric_types(char type, va_list args, t_flags *flags)
{
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int), 0, flags));
	else if (type == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 1, flags));
	else if (type == 'x' || type == 'X')
	{
		if (type == 'X')
			flags->is_upper = 1;
		else
			flags->is_upper = 0;
		return (ft_puthex((void *)va_arg(args, unsigned long), flags));
	}
	else if (type == 'p')
		return (ft_putaddr(va_arg(args, void *), flags));
	else if (type == 'f')
		return (ft_putfloat(va_arg(args, double), flags));
	return (0);
}

int	check_flags(const char *input, int *index, t_flags *flags)
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
	int		count;
	t_flags	flags;

	count = 0;
	if (input == NULL)
		return (0);
	init_flags(&flags);
	va_start(args, input);
	count += check_type(input, args, &flags);
	va_end(args);
	return (count);
}
