/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:11:39 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/19 18:27:42 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	print_number_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nb_l;
	int				count;

	count = 0;
	nb_l = nbr;
	base_len = ft_strlen(base);
	if (nb_l >= base_len)
	{
		count += print_number_base(nb_l / base_len, base);
		count += print_number_base(nb_l % base_len, base);
	}
	else
	{
		count += print_char(base[nb_l]);
	}
	return (count);
}*/

static int	get_hex_size(int nbr)
{
	int				count;
	unsigned int	nbrl;

	count = 0;
	nbrl = nbr;
	if (nbrl >= 16)
	{
		count += get_hex_size(nbrl / 16);
		count += get_hex_size(nbrl % 16);
	}
	else
		count++;
	return (count);
}

/*static int	get_values(char	*prefix, int *len_prec, t_flags *flags, int nbr)
{
	int		len;

	len = get_hex_size(nbr);
	*len_prec = len;
	if (flags->precision > len)
		*len_prec = flags->precision;
	*prefix = '0';
	if (flags->zero && flags->dot && flags->zero_offset > flags->precision)
		*prefix = ' ';
	if (!flags->zero)
		*prefix = ' ';
	if (flags->zero)
		flags->min_width = flags->zero_offset;
	if (flags->precision > flags->min_width)
		flags->min_width = flags->precision;
	return (len);
}

static int	print_x(int is_maj, int len, int nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (nbr == 0 && flags->min_width && flags->min_width < len)
		count += print_char(' ');
	else if (nbr == 0 && flags->dot && !flags->precision
		&& flags->min_width >= len)
		count += print_char(' ');
	else if (!(nbr == 0 && flags->dot && !flags->precision))
	{
		if (is_maj)
			count += print_number_base(nbr, "0123456789ABCDEF");
		else
			count += print_number_base(nbr, "0123456789abcdef");
	}
	return (count);
}*/

int ft_print_hex(unsigned int nbr, int is_maj, t_flags *flags)
{
    int count = 0;
    int len = get_hex_size(nbr);
    int total_len = (flags->precision > len) ? flags->precision : len;
    
    if (flags->sharp && nbr != 0)
        total_len += 2;

    if (!flags->minus && (!flags->zero || flags->dot))
        count += print_padding(count, flags->min_width - total_len, ' ');

    if (flags->sharp && nbr != 0)
        count += print_str(is_maj ? "0X" : "0x");

    if (flags->zero && !flags->dot)
        count += print_padding(count, flags->min_width - total_len, '0');

    count += print_padding(count, flags->precision - len, '0');

    if (!(nbr == 0 && flags->dot && flags->precision == 0))
        count += print_hex_number(nbr, is_maj);

    if (flags->minus)
        count += print_padding(count, flags->min_width - count, ' ');

    return count;
}
