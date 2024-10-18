t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	
	t_list *last = lst;

	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

/*int	main()
{
	t_list *head = NULL;

	t_list *last_content = ft_lstlast(head);
	if (last_content != NULL)
		printf("Le dernier element est : %s\n", (char *)last_content->content);
	else
	printf("La liste est vide.\n");
	return (0);
}*/