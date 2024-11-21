/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:23:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/19 18:22:39 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int print_minus(long *nl, int *len, t_flags *flags)
{
    print_char('-');
    (*nl) = (*nl) * -1;
    (*len)--;  // Réduire la longueur du nombre pour tenir compte du signe '-'
    if (flags->dot)
        (*len)--;  // Réduire encore la longueur si la précision est définie
    return (1);
}*/

static int	num_lenght(long num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		cur++;
	while (num != 0)
	{
		num /= 10;
		cur++;
	}
	return (cur);
}

/*static int print_sign_and_padding(long nl, t_flags *flags, int *count, int total_len)
{
    if (!flags->minus && !flags->zero)
        *count = print_padding(*count, flags->min_width - total_len, ' ');
    if (nl < 0)
        *count += print_char('-');
    else if (flags->plus)
        *count += print_char('+');
    else if (flags->spaces)
        *count += print_char(' ');
    return *count;
}*/

int ft_print_num(long nl, t_flags *flags)
{
    int count;
    int len;
    int total_len;
    int is_negative;

    count = 0;
    is_negative = (nl < 0);
    nl = (nl < 0) ? -nl : nl;
    len = num_lenght(nl);
    total_len = (flags->precision > len) ? flags->precision : len;
    if (is_negative || flags->plus || flags->spaces)
        total_len++;

    if (!flags->minus && (!flags->zero || flags->dot))
        count += print_padding(count, flags->min_width - total_len, ' ');

    if (is_negative)
        count += print_char('-');
    else if (flags->plus)
        count += print_char('+');
    else if (flags->spaces)
        count += print_char(' ');

    if (flags->zero && !flags->dot)
        count += print_padding(count, flags->min_width - total_len, '0');

    count += print_padding(count, flags->precision - len, '0');

    if (!(nl == 0 && flags->dot && flags->precision == 0))
        count += print_number(nl);

    if (flags->minus)
        count += print_padding(count, flags->min_width - count, ' ');

    return count;
}



/*int ft_print_num(long nl, t_flags *flags)
{
    int count = 0;
    int len = num_lenght(nl);
    int padding = 0;
    int is_negative = (nl < 0);

    // Calculer la longueur totale
    int total_len = (flags->precision > len) ? flags->precision : len;
    if (is_negative || flags->plus || flags->spaces)
        total_len++;

    // Padding gauche si nécessaire
    if (!flags->minus && !flags->zero)
        while (count < flags->min_width - total_len)
            count += print_char(' ');

    // Signe ou espace
    if (is_negative)
        count += print_char('-');
    else if (flags->plus)
        count += print_char('+');
    else if (flags->spaces)
        count += print_char(' ');

    // Zéros de padding
    if (flags->zero && !flags->minus && !flags->dot)
        padding = flags->min_width - total_len;
    else if (flags->precision > len)
        padding = flags->precision - len;

    while (padding-- > 0)
        count += print_char('0');

    // Nombre
    if (!(nl == 0 && flags->dot && flags->precision == 0))
        count += print_number(is_negative ? -nl : nl);

    // Padding droit si nécessaire
    if (flags->minus)
        while (count < flags->min_width)
            count += print_char(' ');

    return count;
}*/

