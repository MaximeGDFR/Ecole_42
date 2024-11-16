/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:19:44 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/16 21:22:30 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(char c, t_flags *flags)
{
	int	cur;

	cur = 0;
	while (cur + 1 < flags->min_width)
		cur += print_char(' ');
	cur += print_char(c);
	while (cur < flags->offset)
		cur += print_char(' ');
	return (cur);
}
