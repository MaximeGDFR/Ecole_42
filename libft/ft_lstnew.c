#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

t_list	*ft_lstnew(void *content)
{
	t_list *new_content;

	new_content = (t_list *)malloc(sizeof(t_list));
	if (new_content == NULL)
		return (NULL);

	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}

/*int	main()
{
	int		int_val = 42;
	t_list *int_content = ft_lstnew(&int_val);
	assert(int_content != NULL);
	assert(*(int *)int_content->content == 42);
	assert(int_content->next == NULL);
	printf("Test with int passed !\n");
	
	char	*str_val = "Hello world !";
	t_list *str_content = ft_lstnew(&str_val);
	assert(str_content != NULL);
	assert(*(str *)str_content->content == "Hello world !");
	assert(str_content->next == NULL);
	printf("Test with string passed !\n");

	float	float_val = 42.42;
	t_list *float_content = ft_lstnew(&float_val);
	assert(float_content != NULL);
	assert(*(float *)float_content->content == 42);
	assert(float_content->next == NULL);
	printf("Test with float passed !\n");

	free(int_content);
	free(str_content);
	free(float_content);
	return (0);
}*/