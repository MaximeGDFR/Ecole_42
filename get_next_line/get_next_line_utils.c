/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:05:35 by j                 #+#    #+#             */
/*   Updated: 2024/11/09 12:31:35 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
    char *dup;
    size_t len;
    size_t i;

    if (!s) return NULL;

    len = 0;
    while (s[len])
        len++;
    dup = (char *)malloc(len + 1);
    if (!dup)
    {
        printf("Erreur d'allocation de mémoire dans ft_strdup\n");
        return (NULL);
    }
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}


char	*ft_strjoin(const char *s1, const char *s2)
{
    size_t len1, len2, i;
    char *joined;

    if (!s1 && !s2)
        return NULL;
    if (!s1)
        return ft_strdup(s2);
    if (!s2)
        return ft_strdup(s1);

    len1 = 0;
    while (s1[len1])
        len1++;
    len2 = 0;
    while (s2[len2])
        len2++;

    joined = (char *)malloc(len1 + len2 + 1);
    if (!joined)
    {
        printf("Erreur d'allocation de mémoire dans ft_strjoin\n");
        return (NULL);
    }
    i = 0;
    while (i < len1)
    {
        joined[i] = s1[i];
        i++;
    }
    while (i < len1 + len2)
    {
        joined[i] = s2[i - len1];
        i++;
    }
    joined[i] = '\0';
    return (joined);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;

    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    substr = (char *)malloc(len + 1);
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}

char *ft_strchr(const char *s, int c)
{
    if (!s)
        return NULL;

    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return NULL;
}

size_t ft_strlen(const char *str)
{
    size_t len = 0;

    while (str[len])
        len++;
    return (len);
}