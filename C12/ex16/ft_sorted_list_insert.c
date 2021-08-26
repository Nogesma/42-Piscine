#include "ft_list.h"
#include <stdlib.h>

void	loop(t_list *elem, void *data, int(*cmp)())
{
	t_list	*temp;

	while (elem->next != NULL)
	{
		if (cmp(elem->next->data, data) >= 0)
		{
			temp = ft_create_elem(data);
			temp->next = elem->next;
			elem->next = temp;
			return ;
		}
		elem = elem->next;
	}
	elem->next = ft_create_elem(data);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int(*cmp)())
{
	t_list	*elem;
	t_list	*temp;

	elem = *begin_list;
	if (elem == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	if (cmp(elem->data, data) >= 0)
	{
		temp = ft_create_elem(data);
		temp->next = elem;
		*begin_list = temp;
		return ;
	}
	loop(elem, data, cmp);
}
