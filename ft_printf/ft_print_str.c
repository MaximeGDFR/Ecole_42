/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:43:16 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/16 23:20:54 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	cur;

	cur = 0;
	while (str[cur])
		write(1, &str[cur++], 1);
	return (cur);
}

static int	print_str_size(char *str, int size)
{
	int	cur;

	if (size == -1)
		return (print_str(str));
	cur = 0;
	while (str[cur] && cur < size)
		write(1, &str[cur++], 1);
	return (cur);
}

int	ft_print_str(char *str, t_flags *flags)
{
	int	cur;
	int	len;

	cur = 0;
	if (!str)
	{
		str = "(null)";
		len = 6;
	}
	else
		len = ft_strlen(str);
	while (cur + len < flags->min_width)
		cur += print_char(' ');
	if (!flags->dot)
		flags->precision = -1;
	cur += print_str_size(str, flags->precision);
	while (cur < flags->offset)
		cur += print_char(' ');
	return (cur);
}
