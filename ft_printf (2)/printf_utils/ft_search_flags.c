/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:34:42 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 18:37:55 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(int c)
{
	return ((is_type(c) || is_digit(c) || is_spe(c)));
}

int	is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'p'
		|| c == '%' || c == 'f')
		return (1);
	return (0);
}

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_spe(int c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0'
		|| c == '#' || c == '.' || c == '*')
		return (1);
	return (0);
}
