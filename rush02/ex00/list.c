#include "list.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>

t_list	*ft_create_elem(char c)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->c = c;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, char c)
{
	t_list	*elem;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(c);
		return ;
	}
	elem = *begin_list;
	while (elem->next != NULL)
		elem = elem->next;
	elem->next = ft_create_elem(c);
}

void	ft_list_clear(t_list *begin_list)
{
	t_list	*elem;

	while (begin_list != NULL)
	{
		elem = begin_list;
		begin_list = begin_list->next;
		free(elem);
	}
}

void	ft_print_list(t_list *begin_list)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = begin_list;
	while (temp != NULL)
	{
		i++;
		if (!is_space(temp->c))
			j = i;
		temp = temp->next;
	}
	temp = begin_list;
	i = 0;
	while (temp != NULL)
	{
		if (i < j)
			ft_putchar(temp->c);
		i++;
		temp = temp->next;
	}
}

void	print_linked_array(t_list	**t)
{
	int	i;

	i = -1;
	while (t[++i + 1] != NULL)
	{
		ft_print_list(t[i]);
		ft_putchar(' ');
		ft_list_clear(t[i]);
	}
	ft_print_list(t[i]);
	ft_putchar('\n');
	ft_list_clear(t[i]);
	free(t);
}
