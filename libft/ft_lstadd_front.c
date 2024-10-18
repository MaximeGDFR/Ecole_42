#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return (NULL);
	
	new->next = *lst;
	*lst = new;
}

/*int	main()
{
	t_list *head = NULL;
	t_list *new_content = ft_lstnew("Hello");

	ft+ft_lstadd_front(&head, new_content);

	return (0);
}*/