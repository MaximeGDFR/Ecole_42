/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:38:46 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/22 15:59:13 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_address(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_address(n / 16);
		ft_print_address(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else if (n >= 10)
			ft_print_c((n - 10) + 'a');
	}
}

int	ft_print_ptr_with_format(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_print_full_str(PTRNULL);
		return (count);
	}
	count += ft_print_full_str("0x");
	ft_print_address(n);
	count += ft_pointer_length(n);
	return (count);
}

int	ft_print_ptr(unsigned long int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n == 0)
		flags.width -= ft_strlen(PTRNULL) - 1;
	else
		flags.width -= 2;
	if (flags.left == 1)
		count += ft_print_ptr_with_format(n);
	count += ft_add_padding(flags.width, ft_pointer_length(n), 0);
	if (flags.left == 0)
		count += ft_print_ptr_with_format(n);
	return (count);
}
