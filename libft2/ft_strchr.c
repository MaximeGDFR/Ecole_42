/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:30:01 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/19 13:48:44 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

/*int main() {
    const char *str = "Hello, world!";
    char ch = 'o';
    
    char *result = strchr(str, ch);
    
    if (result != NULL)
    {
        printf("'%c' a ete trouve a la position : %ld\n", ch, result - str);
    }
    else
    {
        printf("Le caractere '%c' n'a pas ete trouve.\n", ch);
    }
    
    return (0);
}*/