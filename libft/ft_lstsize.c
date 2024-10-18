int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	
	t_list *current = *lst;

	while (current != NULL)
	{
		i++;
		current = current->next
	}
	return (i);
}

/*int	main()
{
	t_list *head = NULL;

	int	size = ft_lstsize(head);
	printf("La taille de la liste est : %s\n", size);
	return (0);
}*/