/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:54 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/17 12:07:17 by maximegdfr       ###   ########.fr       */
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
	int		sharp;
	int		spaces;
	int		plus;
	int		min_width;
	int		minus;
	int		dot;
	int		precision;
	int		offset;
	int		zero;
	int		zero_offset;
}	t_flags;

/********************** FT_PRINTF **********************/
int		ft_printf(const char *format, ...);
int		ft_print_char(char c, t_flags *flags);
int		ft_print_str(char *str, t_flags *flags);
int		ft_print_ptr(void *ptr, t_flags *flags);
int		ft_print_num(long nl, t_flags *flags);
int		ft_print_u_num(unsigned long nl, t_flags *flags);
int		ft_print_hex(int nbr, int is_maj, t_flags *flags);

/********************** UTILS **********************/
void	init_flags(t_flags *flags);
int		check_type(const char *input, va_list *params, t_flags *flags);
void	check_flags(const char *input, int *cur, t_flags *flags);
int		check(const char *input, va_list *params, int *cur);
int		ft_strlen(char *str);
int		ft_atoi(const char *str, int *o_cur);
int		print_str(char *str);
int		print_char(char c);
int		in_set(char c, char *set);
int		print_number(long nl);
int		print_long_as_hex(unsigned long addr);

#endif