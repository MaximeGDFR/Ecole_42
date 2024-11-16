/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:23:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/16 22:25:26 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_minus(long *nl, int *len, t_flags *flags)
{
	print_char('-');
	(*nl) = (*nl) * -1;
	(*len)--;
	if (flags->dot)
		(*len)--;
	return (1);
}

static int	num_lenght(long num)
{
	int		cur;

	cur = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		cur++;
	while (num != 0)
	{
		num /= 10;
		cur++;
	}
	return (cur);
}

static int	get_values(char *prefix, int *len_prec, t_flags *flags, long nl)
{
	int		len;

	len = num_lenght(nl);
	*len_prec = len;
	if (flags->precision > len)
		*len_prec = flags->precision;
	if (nl < 0 && flags->zero_offset > len && flags->precision > len)
		(*len_prec)++;
	if (nl < 0 && flags->dot && flags->zero_offset > flags->precision)
		len++;
	*prefix = '0';
	if (flags->zero && flags->dot && flags->zero_offset > flags->precision)
		*prefix = ' ';
	if (!flags->zero)
		*prefix = ' ';
	if (flags->zero)
		flags->min_width = flags->zero_offset;
	if (flags->precision > flags->min_width)
		flags->min_width = flags->precision;
	return (len);
}

static int	print_d_and_i(int len, long nl, t_flags *flags)
{
	int		count;

	count = 0;
	if (nl == 0 && flags->min_width && flags->min_width < len)
		count += print_char(' ');
	else if (nl == 0 && flags->dot && !flags->precision
		&& flags->min_width >= len)
		count += print_char(' ');
	else if (!(nl == 0 && flags->dot && !flags->precision))
		count += print_number(nl);
	return (count);
}

int	ft_print_num(long nl, t_flags *flags)
{
	int		count;
	int		len;
	char	prefix;
	int		len_prec;

	count = 0;
	len = get_values(&prefix, &len_prec, flags, nl);
	while (prefix == ' ' && len_prec + count < flags->min_width)
		count += print_char(' ');
	if (nl < 0)
		count += print_minus(&nl, &len, flags);
	else if (flags->spaces && nl >= 0 && !flags->plus && !flags->dot)
		count += print_char(' ');
	else if (flags->plus && nl >= 0 && !flags->dot)
		count += print_char('+');
	while (len + count < flags->min_width)
		count += print_char('0');
	count += print_d_and_i(len, nl, flags);
	while (count < flags->offset)
		count += print_char(' ');
	return (count);
}
