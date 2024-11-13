/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:44:40 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 21:49:13 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->precision = 0;
}

int	check_precision(const char *input, int *index, t_flags *flags)
{
	if (input[*index] == '.')
	{
		(*index)++;
		flags->dot = 1;
		flags->precision = 0;
		if (input[*index] >= '0' && input[*index] <= '9')
		{
			while (input[*index] >= '0' && input[*index] <= '9')
			{
				flags->precision = flags->precision * 10
					+ (input[*index] - '0');
				(*index)++;
			}
		}
	}
	return (1);
}

int	check_width(const char *input, int *index, t_flags *flags)
{
	if (input[*index] >= '0' && input[*index] <= '9')
	{
		flags->width = 0;
		while (input[*index] >= '0' && input[*index] <= '9')
		{
			flags->width = flags->width * 10 + (input[*index] - '0');
			(*index)++;
		}
	}
	return (1);
}

int	handle_padding(int count, int padding, int fill_char)
{
	while (padding > 0)
	{
		count += write(1, &fill_char, 1);
		padding--;
	}
	return (count);
}
