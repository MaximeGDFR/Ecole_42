/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:31:48 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/02 16:31:19 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define PTRNULL "(nil)"

typedef struct s_flags
{
	int		spec;
	int		width;
	int		left;
	int		zero;
	int		star;
	int		precision;
	int		hash;
	int		space;
	int		plus;
}	t_flags;

/* -------------------- ft_printf -------------------- */
int		ft_printf(const char *format, ...);
int		ft_parse_flags(const char *str, int i, va_list args, t_flags *flags);
int		ft_print_argument(char type, va_list args, t_flags flags);

/* ---------- Print %c ---------- */
int		ft_print_char(char c, t_flags flags);
int		ft_print_c(char c);

/* ---------- Print %s ---------- */
int		ft_print_string(const char *str, t_flags flags);
int		ft_print_full_str(const char *str);
int		ft_print_partial_str(const char *str, int precision);
int		ft_print_sign_or_space(int n, t_flags *flags);

/* ---------- Print %d / %i ---------- */
int		ft_print_number(int n, t_flags flags);
int		ft_print_sign_or_space(int n, t_flags *flags);
int		ft_print_int_with_format(char *nbstr, int n, t_flags flags);
int		ft_print_full_int(char *nbstr, int n, t_flags flags);

/* ---------- Print %u ---------- */
int		ft_print_unsigned(unsigned int n, t_flags flags);
int		ft_print_unsigned_int_with_pre(char *nbstr, t_flags flags);
int		ft_print_unsigned_int_with_format(char *nbstr, t_flags flags);

/* ---------- Print %x / %X ---------- */
int		ft_print_hex(unsigned int n, int is_upper, t_flags flags);
int		ft_print_hex_prefix(int is_upper);
int		ft_print_hex_with_pre(char *nbstr, int n, int is_upper, t_flags flags);
int		ft_print_hex_with_format(char *nbstr, int n, int is_upper,
			t_flags flags);

/* ---------- Print %p ---------- */
int		ft_print_ptr(unsigned long int n, t_flags flags);
int		ft_print_ptr_with_format(unsigned long int n);
void	ft_print_address(unsigned long int n);

/* ---------- Helper Functions ---------- */
char	*ft_printf_itoa(long nb);
char	*ft_printf_utoa(unsigned int nb);
char	*ft_printf_xtoa(unsigned long int nb, int is_upper);
int		ft_unsigned_int_length(unsigned int n);
int		ft_hex_length(unsigned int n);
int		ft_pointer_length(unsigned long int n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

/* ---------- Flags Functions ------------ */
int		ft_add_padding(int total_width, int size, int zero);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);
int		ft_isdigit(int c);
t_flags	ft_flags_init(void);
t_flags	ft_flag_left(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
int		ft_flag_precision(const char *str, int pos,
			va_list args, t_flags *flags);

#endif
