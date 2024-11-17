/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:47 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/17 13:04:35 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char *input, va_list *params, t_flags *flags)
{
	int	count;

	count = 0;
	if (input[1] == 'c')
		count += ft_print_char(va_arg(*params, int), flags);
	else if (input[1] == 's')
		count += ft_print_str(va_arg(*params, char *), flags);
	else if (input[1] == 'p')
		count += ft_print_ptr(va_arg(*params, void *), flags);
	else if (input[1] == 'd' || input[1] == 'i')
		count += ft_print_num(va_arg(*params, int), flags);
	else if (input[1] == 'u')
		count += ft_print_u_num(va_arg(*params, unsigned int), flags);
	else if (input[1] == 'x')
		count += ft_print_hex(va_arg(*params, int), 0, flags);
	else if (input[1] == 'X')
		count += ft_print_hex(va_arg(*params, int), 1, flags);
	else if (input[1] == '%')
		count += print_char('%');
	return (count);
}

void	check_flags(const char *input, int *cur, t_flags *flags)
{
	if (input[1] == '#')
		flags->sharp = 1;
	else if (input[1] == ' ')
		flags->spaces = 1;
	else if (input[1] == '+')
		flags->plus = 1;
	else if (input[1] == '0')
	{
		flags->zero_offset = ft_atoi(input + 2, cur);
		flags->zero = 1;
	}
	else if (input[1] == '-')
	{
		flags->offset = ft_atoi(input + 2, cur);
		flags->minus = 1;
	}
	else if (input[1] == '.')
	{
		flags->precision = ft_atoi(input + 2, cur);
		flags->precision = 1;
	}
}

int	check(const char *input, va_list *params, int *cur)
{
	int		count;
	t_flags	flags;

	count = 0;
	init_flags(&flags);
	while (in_set(input[(*cur) + 1], "0123456789# +-."))
	{
		if (in_set(input[(*cur) + 1], "# +0-."))
			check_flags(input + (*cur), cur, &flags);
		else
		{
			flags.min_width = ft_atoi(input + (*cur) + 1, cur);
			(*cur)--;
		}
		(*cur)++;
	}
	count += check_type(input + (*cur), params, &flags);
	(*cur)++;
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list		params;
	int			cur;
	int			count;

	cur = 0;
	count = 0;
	va_start(params, input);
	while (input[cur])
	{
		if (input[cur] == '%')
			count += check(input, &params, &cur);
		else
			count += print_char(input[cur]);
		cur++;
	}
	va_end(params);
	return (count);
}
