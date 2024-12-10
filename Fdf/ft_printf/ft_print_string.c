/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:46:06 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/22 15:50:19 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_str_with_pre_pad(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += ft_add_padding(flags.precision, ft_strlen(str), 0);
		count += ft_print_partial_str(str, flags.precision);
	}
	else
		count += ft_print_partial_str(str, ft_strlen(str));
	return (count);
}

int	ft_print_partial_str(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}

int	ft_print_full_str(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int	ft_print_string(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (str == NULL && flags.precision >= 0 && flags.precision < 6)
	{
		count += ft_add_padding(flags.width, 0, 0);
		return (count);
	}
	if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		count += ft_print_str_with_pre_pad(str, flags);
	if (flags.precision >= 0)
		count += ft_add_padding(flags.width, flags.precision, 0);
	else
		count += ft_add_padding(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		count += ft_print_str_with_pre_pad(str, flags);
	return (count);
}
