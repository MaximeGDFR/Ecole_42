/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:31:12 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/21 19:32:35 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (malloc(1));
	end = start;
	while (s1[end] != '\0')
		end++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

/*int main()
{
    char const *s1 = "   Hello World!   ";
    char const *set = " ";
    char *trimmed;

    trimmed = ft_strtrim(s1, set);

    if (trimmed == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return (1);
    }

    printf("Avant trim : '%s'\n", s1);
    printf("Après trim : '%s'\n", trimmed);

    free(trimmed);

    return (0);
}*/