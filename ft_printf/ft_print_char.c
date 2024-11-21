/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:19:44 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/19 18:20:08 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(char c, t_flags *flags)
{
	int	cur;

	cur = 0;
	while (cur + 1 < flags->min_width)
		cur += print_char(' ');
	cur += print_char(c);
	while (cur < flags->offset)
		cur += print_char(' ');
	return (cur);
}
int num_lenght_u(unsigned long num)
{
    int cur;

    cur = 0;
    if (num == 0)
        return (1);
    while (num != 0)
    {
        num /= 10;
        cur++;
    }
    return (cur);
}

int print_u_number(unsigned long nl)
{
    int count;

    count = 0;
    if (nl >= 10)
        count += print_u_number(nl / 10);
    count += print_char((nl % 10) + '0');
    return (count);
}

int print_padding(int count, int width, char pad_char)
{
    while (count < width)
    {
        print_char(pad_char);
        count++;
    }
    return count;
}
