/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:31:08 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/22 17:42:03 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*occ;

	if (!s)
		return (NULL);
	i = 0;
	occ = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			occ = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (occ);
}

/*int main()
{
    const char *str = "teste";
    char ch = '\0';
    char *result = ft_strrchr(str, ch);
    
    if (result != NULL)
        printf("Last '%c' est a la position : %ld\n", ch, result - str);
    else
        printf("Le caractere '%c' n'a pas ete trouve.\n", ch);
    return (0);
}*/