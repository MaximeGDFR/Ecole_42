/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:28:32 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/19 12:53:07 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    int i;

    i = 0;
    if (new == NULL)
        return ;
    
    t_list *current = *lst;

    if (*lst == NULL)
        *lst = new;
    else
    {
        while (current->next != NULL)
        {
            i++;
            current = current->next;
        }
        current->next = new;
    }
}

/*int main()
{
    t_list *head = NULL;
	t_list *new_content = ft_lstadd_back("Hello");

	ft_lstadd_back(&head, new_content);

	return (0);
}*/