/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:58:40 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 19:00:49 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(char *nb_str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += pad_width(flags.precision - 1, ft_strlen(nb_str) - 1, 1);
	count += print_string(nb_str);
	return (count);
}

int	print_unsigned_int(char *nb_str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += print_u(nb_str, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nb_str))
		flags.precision = ft_strlen(nb_str);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += pad_width(flags.width, 0, 0);
	}
	else
		count += pad_width(flags.width, ft_strlen(nb_str), flags.zero);
	if (flags.minus == 0)
		count += print_u(nb_str, flags);
	return (count);
}

int	ft_print_unsigned_number(unsigned n, t_flags flags)
{
	char	*nb_str;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += pad_width(flags.width, 0, 0);
		return (count);
	}
	nb_str = print_utoa(n);
	if (!nb_str)
		return (0);
	count += print_unsigned_int(nb_str, flags);
	free(nb_str);
	return (count);
}
