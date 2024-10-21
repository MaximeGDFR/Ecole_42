/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:30:15 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/19 15:06:51 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*empty_str;
	int		total_len;
	char	*result;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
	{
		empty_str = (char *)malloc(1);
		if (empty_str == NULL)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((total_len + 1) * sizeof (char));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

/*int main()
{
    const char *s1 = "Hello ";
    const char *s2 = "world !";

    char *result = ft_strjoin(s1, s2);
    if (result != NULL)
    {
        printf("Result : %s\n", result);
        free(result);
    }

    return (0);
}*/