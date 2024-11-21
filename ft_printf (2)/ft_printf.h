/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:31:48 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/21 19:06:43 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define PTRNULL "(nil)"

typedef struct s_flags
{
	int		spe;
	int		width;
	int		minus;
	int		zero;
	int		star;
	int		precision;
	int		hash;
	int		space;
	int		plus;
}	t_flags;

/*************** Main Functions ***************/
int		ft_printf(const char *format, ...);
int		ft_print_char(char c, t_flags flags);
int		ft_print_string(const char *str, t_flags flags);
int		ft_print_number(int n, t_flags flags);
int		ft_print_unsigned_number(unsigned n, t_flags flags);
int		ft_print_hex(unsigned int n, int is_upper, t_flags flags);
int		ft_print_pointer(unsigned long n, t_flags flags);

int		print_arg(char type, va_list args, t_flags flags);
int		parsing_flags(const char *str, int i, va_list args, t_flags *flags);
int		parsing(char *str, va_list args);
/*************** Specific Functions ***************/
int		print_char(char c);

int		print_str(const char *str, t_flags flags);
int		print_str_pre(const char *str, int precision);
int		print_string(const char *str);

int		print_num(char *nb_str, int n, t_flags flags);
int		print_sign(int n, t_flags *flags);
int		print_int(char *nb_str, int n, t_flags flags);

int		print_u(char *nb_str, t_flags flags);
int		print_unsigned_int(char *nb_str, t_flags flags);

int		print_prefix_hex(int is_upper);
int		print_x(char *nb_str, int n, int is_upper, t_flags flags);
int		print_hex(char *nb_str, int n, int is_upper, t_flags flags);

void	print_addr(unsigned long n);
int		print_p(unsigned long n);
/*************** Flags Functions ***************/
int		is_flag(int c);
int		is_type(int c);
int		is_digit(int c);
int		is_spe(int c);
t_flags	init_flags(t_flags *flags);
t_flags	handle_minus(t_flags flags);
t_flags	handle_digits(char c, t_flags flags);
t_flags	handle_width(va_list args, t_flags flags);
int		handle_precision(const char *str, int pos,
			va_list args, t_flags *flags);
/*************** Padding Functions ***************/
int		pad_width(int total_width, int size, int zero);
/*************** Other Functions ***************/
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		pointer_length(unsigned long n);
int		unsigned_int_length(unsigned int n);
int		hexa_length(unsigned int n);
char	*print_itoa(long num);
char	*print_utoa(unsigned int num);
char	*print_xtoa(unsigned long num, int is_upper);
void	ft_bzero(void *s, size_t n);

#endif
