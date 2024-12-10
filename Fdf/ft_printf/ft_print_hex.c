/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:09:12 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/22 16:02:36 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_prefix(int is_upper)
{
	if (is_upper == 1)
		ft_print_full_str("0X");
	else
		ft_print_full_str("0x");
	return (2);
}

int	ft_print_hex_with_pre(char *nbstr, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 0 && flags.hash == 1 && n != 0)
		count += ft_print_hex_prefix(is_upper);
	if (flags.precision >= 0)
		count += ft_add_padding(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_full_str(nbstr);
	return (count);
}

int	ft_print_hex_with_format(char *nbstr, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1 && flags.hash == 1 && n != 0)
		count += ft_print_hex_prefix(is_upper);
	if (flags.left == 1)
		count += ft_print_hex_with_pre(nbstr, n, is_upper, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_add_padding(flags.width, 0, 0);
	}
	else
		count += ft_add_padding(flags.width,
				ft_strlen(nbstr) + (flags.hash * 2), flags.zero);
	if (flags.left == 0)
		count += ft_print_hex_with_pre(nbstr, n, is_upper, flags);
	return (count);
}

int	ft_print_hex(unsigned int n, int is_upper, t_flags flags)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_add_padding(flags.width, 0, 0);
		return (count);
	}
	nbstr = ft_printf_xtoa(n, is_upper);
	if (!nbstr)
		return (0);
	count += ft_print_hex_with_format(nbstr, n, is_upper, flags);
	free(nbstr);
	return (count);
}
