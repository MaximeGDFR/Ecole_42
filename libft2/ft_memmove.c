/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:27:35 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/22 16:07:23 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL || src == NULL)
		return (NULL);
	if (d < s || d >= s + n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			d[i] = s[i];
	}
	return (d);
}

/*int main()
{
    char s1 [20] = "Hello world";
    char s2 [] = "Hello world !";
    size_t n = 13;

    printf("Avant memmove: s1 = %s, s2 = %s\n", s1, s2);
    ft_memmove(s1, s2, n);
    printf("Apres memmove: s1 = %s\n", s1);

    return (0);
}*/