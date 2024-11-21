/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:47 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/19 17:50:13 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_type(const char *input, va_list params, t_flags *flags)
{
	int	count;

	count = 0;
	if (*input == 'c')
		count += ft_print_char(va_arg(params, int), flags);
	else if (*input == 's')
		count += ft_print_str(va_arg(params, char *), flags);
	else if (*input == 'p')
		count += ft_print_ptr(va_arg(params, void *), flags);
	else if (*input == 'd' || input[1] == 'i')
		count += ft_print_num(va_arg(params, int), flags);
	else if (*input == 'u')
		count += ft_print_u_num(va_arg(params, unsigned int), flags);
	else if (*input == 'x')
		count += ft_print_hex(va_arg(params, unsigned int), 0, flags);
	else if (*input == 'X')
		count += ft_print_hex(va_arg(params, unsigned int), 1, flags);
	else if (*input == '%')
		count += print_char('%');
	return (count);
}

void check_flags(const char *input, int *cur, t_flags *flags)
{
    while (input[*cur])
    {
        if (input[*cur] == '#')
            flags->sharp = 1;
        else if (input[*cur] == ' ')
            flags->spaces = 1;
        else if (input[*cur] == '+')
            flags->plus = 1;
        else if (input[*cur] == '-')
            flags->minus = 1;
        else if (input[*cur] == '0' && !flags->dot && flags->min_width == 0)
            flags->zero = 1;
        else if (input[*cur] == '.')
        {
            flags->dot = 1;
            (*cur)++;
            flags->precision = 0;
            while (ft_isdigit(input[*cur]))
            {
                flags->precision = flags->precision * 10 + (input[*cur] - '0');
                (*cur)++;
            }
            (*cur)--; // Ajustement pour compenser l'incrémentation à la fin de la boucle
        }
        else if (ft_isdigit(input[*cur]))
        {
            flags->min_width = flags->min_width * 10 + (input[*cur] - '0');
        }
        else
            break;
        (*cur)++;
    }
}

int	check(const char *input, va_list params, int *cur)
{
	int		count;
	t_flags	flags;

	count = 0;
	init_flags(&flags);
	(*cur)++;
	check_flags(input, cur, &flags);
	count += check_type(input + (*cur), params, &flags);
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
			count += check(input, params, &cur);
		else
			count += print_char(input[cur]);
		cur++;
	}
	va_end(params);
	return (count);
}
