/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:02:22 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/22 08:58:32 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_print_c(c);
	count += ft_pad_width(flags.width, 1, flags.zero);
	if (flags.left == 0)
		count += ft_print_c(c);
	return (count);
}
