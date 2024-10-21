/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:28:21 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/19 12:28:22 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_isspace(int c)
{
	if (c == EOF)
		return (0);
	if ((unsigned char)c >= 9 && (unsigned char)c <= 13
		|| (unsigned char)c == 32)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int c = ' ';
	int	result;

	result = ft_isspace(c);
	printf("%d\n", result);
	return (0);
}*/