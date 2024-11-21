/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:09:12 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 18:46:52 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prefix_hex(int is_upper)
{
	if (is_upper)
		print_string("0X");
	else
		print_string("0x");
	return (2);
}

int	print_x(char *nb_str, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 0 && flags.hash == 1 && n != 0)
		count += print_prefix_hex(is_upper);
	if (flags.precision >= 0)
		count += pad_width(flags.precision - 1, ft_strlen(nb_str) - 1, 1);
	count += print_string(nb_str);
	return (count);
}

int	print_hex(char *nb_str, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1 && flags.hash == 1 && n != 0)
		count += print_prefix_hex(is_upper);
	if (flags.minus == 1)
		count += print_x(nb_str, n, is_upper, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nb_str))
		flags.precision = ft_strlen(nb_str);
	if (flags.precision >= 0)
	{
		flags.width = flags.precision;
		count += pad_width(flags.width, 0, 0);
	}
	else
		count += pad_width(flags.width, ft_strlen(nb_str) + (flags.hash * 2),
				flags.zero);
	if (flags.minus == 0)
		count += print_x(nb_str, n, is_upper, flags);
	return (count);
}

int	ft_print_hex(unsigned int n, int is_upper, t_flags flags)
{
	char	*nb_str;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += pad_width(flags.width, 0, 0);
		return (count);
	}
	nb_str = print_xtoa(n, is_upper);
	if (!nb_str)
		return (0);
	count += print_hex(nb_str, n, is_upper, flags);
	free(nb_str);
	return (count);
}
