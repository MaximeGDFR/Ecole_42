/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:29:56 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/24 15:10:52 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	words;
	int	i;

	count = 0;
	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !words)
		{
			words++;
			count++;
		}
		else if (s[i] == c)
		{
			words = 0;
		}
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(n + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n && s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	result = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[j++] = ft_strndup(&s[start], i-- - start);
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}

/*int	main()
{
	char	*str = "hello!";
	char	c = ' ';
	char	**result;
	int		i;

	result = ft_split(str, c);
	for (i = 0; result[i] != NULL; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}*/