/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:43:16 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/19 18:20:34 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	cur;

	if (str == NULL)
		str = "(null)";
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

int ft_print_str(char *str, t_flags *flags)
{
    int count = 0;
    int len;

    if (!str)
        str = "(null)";

    len = ft_strlen(str);
    if (flags->dot && flags->precision < len)
        len = flags->precision;

    if (!flags->minus)
        count += print_padding(count, flags->min_width - len, ' ');

    count += print_str_size(str, len);

    if (flags->minus)
        count += print_padding(count, flags->min_width - count, ' ');

    return count;
}

