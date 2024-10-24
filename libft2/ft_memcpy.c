/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:29:20 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/24 16:36:04 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	if (dest == NULL || src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int main()
{
	char dest [10] = "xxxxxxxxx";
    char src [] = "abcde";
    ft_memcpy(dest, src, 5);
	//size_t n = 0;

    //printf("%p\n", memcpy(dest, src, n));
    //printf("%p\n", ft_memcpy(dest, src, n));
	printf("%s\n", dest);

    return (0);
}

/*Test 3 : manque un caractere*/