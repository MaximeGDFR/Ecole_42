/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:46:06 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 18:37:39 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += pad_width(flags.precision, ft_strlen(str), 0);
		count += print_str_pre(str, flags.precision);
	}
	else
		count += print_str_pre(str, ft_strlen(str));
	return (count);
}

int	print_str_pre(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}

int	print_string(const char *str)
{
	int	length;

	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	length = 0;
	while (str[length])
		length++;
	write(1, str, length);
	return (length);
}

int	ft_print_string(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (str == NULL && flags.precision >= 0 && flags.precision < 6)
	{
		count += pad_width(flags.width, 0, 0);
		return (count);
	}
	if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.minus == 1)
		count += print_str(str, flags);
	if (flags.precision >= 0)
		count += pad_width(flags.width, flags.precision, 0);
	else
		count += pad_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += print_str(str, flags);
	return (count);
}
