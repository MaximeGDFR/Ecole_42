/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:54 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 16:27:30 by maximegdfr       ###   ########.fr       */
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
	int		is_upper;
}	t_flags;

/********************** FT_PRINTF **********************/
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb, int is_unsigned, t_flags *flags);
int		ft_puthex(unsigned long nb, char c, t_flags *flags);
int		ft_putaddr(unsigned long addr);
int		ft_putfloat(double nb, t_flags *flags);

/********************** UTILS **********************/
void	init_flags(t_flags *flags);
int		check_width(const char *input, int *index, t_flags *flags);
int		check_precision(const char *input, int *index, t_flags *flags);
int		put_padding(int count, int spaces, int is_zero);
int		get_num_lenght(int nb);
int		is_negative(int count, int n, int is_unsigned);
int		print_number(int n, t_flags *flags, int is_unsigned);
char	*reorder_addr(char *addr, int len);
int		write_addr(unsigned long addr, char *buffer, int is_upper);
int		len_before_dot(double nb);
int		before_dot(int int_part, t_flags *flags);
int		after_dot(double nb, int precision, t_flags *flags);

#endif