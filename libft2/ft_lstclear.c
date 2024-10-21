/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:26:25 by mgodefro          #+#    #+#             */
/*   Updated: 2024/10/19 12:53:17 by mgodefro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void(*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	temp = current;
	if (*lst == NULL)
		return ;
	while (current != NULL)
	{
		del(current->content);
		temp = current->next;
		free(current);
		current = temp;
	}
	*lst = NULL;
}
