/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:29:25 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/10 16:58:09 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;

	ptr = s;
	value = (unsigned char)c;
	while (n--)
		*ptr++ = value;
	return (s);
}

/*int main()
{
    char array [10] = "abcdefghi";
    int i = 0;
    int n = 3;
    int c = 'X';

    ft_memset(array, c, n * sizeof(char));

    while (i < 10)
    {
        printf("%c", array[i]);
        i++;
    }
    printf("\n");

    return (0);
}*/