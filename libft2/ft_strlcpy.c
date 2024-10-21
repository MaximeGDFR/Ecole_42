/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:30:26 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/21 10:47:55 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

/*int	main(void)
{
	char src [] = "Hello";
	char dest [1];
	unsigned int size = 1;

	ft_strlcpy(dest, src, size);
	printf("Src : %s\n", src);
	printf("Size src : 14\n");
	printf("Dest : %s\n", dest);
	printf("Size dest : %d\n", size);
	return (0);
}*/