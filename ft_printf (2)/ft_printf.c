/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:32:33 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 19:18:13 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char type, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_print_char('%', flags);
	else if (type == 'c')
		count += ft_print_char(va_arg(args, int), flags);
	else if (type == 's')
		count += ft_print_string(va_arg(args, char *), flags);
	else if (type == 'd' || type == 'i')
		count += ft_print_number(va_arg(args, int), flags);
	else if (type == 'u')
		count += ft_print_unsigned_number(va_arg(args, unsigned int), flags);
	else if (type == 'x' || type == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 0, flags);
	else if (type == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1, flags);
	else if (type == 'p')
		count += ft_print_pointer((unsigned long)va_arg(args, void *), flags);
	return (count);
}

int	parsing_flags(const char *str, int i, va_list args, t_flags *flags)
{
	while (str[++i] && is_flag(str[i]))
	{
		if (str[i] == '-')
			*flags = handle_minus(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->minus == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = handle_precision(str, i, args, flags);
		if (str[i] == '*')
			*flags = handle_width(args, *flags);
		if (is_digit(str[i]))
			*flags = handle_digits(str[i], *flags);
		if (is_type(str[i]))
		{
			flags->spe = str[i];
			break ;
		}
	}
	return (i);
}

int	parsing(char *str, va_list args)
{
	int		i;
	int		x;
	int		count;
	t_flags	flags;

	i = -1;
	count = 0;
	while (str[++i])
	{
		flags = init_flags(&flags);
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			x = parsing_flags(str, i, args, &flags);
			if (flags.spe > 0)
				i = x;
			if (str[i] != '\0' && flags.spe > 0 && is_type(str[i]))
				count += print_arg(str[i], args, flags);
			else if (str[i] != '\0')
				count += print_char(str[i]);
		}
		else
			count += print_char(str[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*str;

	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	count = 0;
	va_start(args, format);
	count = parsing(str, args);
	va_end(args);
	free(str);
	return (count);
}
