/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:54 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 21:52:04 by maximegdfr       ###   ########.fr       */
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
int		ft_putstr(const char *str);
int		ft_putnbr(int nb, int is_unsigned, t_flags *flags);
int		ft_puthex(void *ptr, t_flags *flags);
int		ft_putaddr(void *ptr, t_flags *flags);
int		ft_putfloat(double nb, t_flags *flags);

/********************** UTILS **********************/
void	init_flags(t_flags *flags);
int		check_flags(const char *input, int *index, t_flags *flags);
int		check_width(const char *input, int *index, t_flags *flags);
int		check_precision(const char *input, int *index, t_flags *flags);
int		handle_numeric_types(char type, va_list args, t_flags *flags);
int		handle_padding(int count, int padding, int fill_char);
int		get_num_lenght(int nb, int is_unsigned);
int		is_negative(int count, int n, int is_unsigned);
int		print_number(int n, t_flags *flags, int is_unsigned);
char	*reorder_addr(char *addr, int len);
int		write_addr_p(unsigned long addr, char *buf, int len);
int		write_addr_x(unsigned long addr, char *buf, int len, t_flags *flags);
int		len_before_dot(double nb);
int		before_dot(int int_part, t_flags *flags);
int		after_dot(double nb, int precision);

#endif