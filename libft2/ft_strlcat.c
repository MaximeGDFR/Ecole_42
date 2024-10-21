/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:30:21 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/21 11:24:19 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	i;
	unsigned int	j;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (size <= dest_size)
		return (src_size + dest_size);
	i = dest_size;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_size + src_size);
}

/*int main()
{
    char dest [] = "iudwiubUBUW";
    char src [] = "";
    unsigned int    size;
    unsigned int    result;

    size = 5;
    printf("Dest : %s\nSrc : %s\nSize : %d\n", dest, src, size);
    result = ft_strlcat(dest, src, size);
    printf("Size total : %d", result);
    return (0);
}*/