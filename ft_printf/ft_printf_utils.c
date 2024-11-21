/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:44:40 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/19 17:29:24 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->sharp = 0;
	flags->spaces = 0;
	flags->plus = 0;
	flags->min_width = 0;
	flags->minus = 0;
	flags->dot = 0;
	flags->precision = -1;
	flags->offset = 0;
	flags->zero = 0;
	flags->zero_offset = 0;
}

int	ft_strlen(char *str)
{
	int	cur;

	cur = 0;
	if (!str)
		return (cur);
	while (str[cur])
		cur++;
	return (cur);
}

int	ft_atoi(const char *str, int *o_cur)
{
	int	cur;
	int	num;

	cur = 0;
	num = 0;
	while (str[cur] >= '0' && str[cur] <= '9')
	{
		num = num * 10 + str[cur] - '0';
		cur++;
		(*o_cur)++;
	}
	return (num);
}

int	in_set(char c, char *set)
{
	int	cur;

	cur = -1;
	while (set[++cur])
		if (set[cur] == c)
			return (1);
	return (0);
}

int	print_number(long nl)
{
	int		count;
	long	num;

	count = 0;
	if (nl < 0)
	{
		count += print_char('-');
		num = -nl;
	}
	else
		num = nl;
	if (num >= 10)
		count += print_number(num / 10);
	count += print_char((num % 10) + '0');
	return (count);
}
