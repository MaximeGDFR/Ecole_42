/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:54 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/12 19:26:07 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flags
{
	int		plus;
	int		space;
	int		hash;
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		precision;
}	t_flags;

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putnbr(int nb, int is_unsigned, t_flags *flags);
int	ft_puthex(unsigned long nb, char c);
int	ft_putaddr(unsigned long addr);

#endif