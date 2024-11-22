/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:07:00 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/22 10:25:38 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pad_width(int total_width, int size, int zero)
{
	int	count;

	count = 0;
	while (total_width - size > 0)
	{
		if (zero)
			count += ft_print_c('0');
		else
			count += ft_print_c(' ');
		total_width--;
	}
	return (count);
}
