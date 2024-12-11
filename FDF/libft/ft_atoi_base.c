/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:49:28 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 23:55:29 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_base(char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_base_is_valid(const char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

static const char	*ft_skip_spaces_sign(const char *str, int *sign)
{
	*sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int		result;
	int		sign;
	int		base_len;
	int		value;

	if (!str || !base || !ft_base_is_valid(base))
		return (0);
	base_len = 0;
	while (base[base_len])
		base_len++;
	str = ft_skip_spaces_sign(str, &sign);
	result = 0;
	value = ft_is_in_base(*str, base);
	while (*str && value != -1)
	{
		result = result * base_len + value;
		str++;
	}
	return (result * sign);
}
