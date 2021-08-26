#include "ft_list.h"
#include <stdlib.h>

void	free_elem(t_list	*elem, void(*free_fct)(void*))
{
	free_fct(elem->data);
	free(elem);
}

void	ft_list_remove_if(t_list **begin_list, void*data_ref, int(*cmp)(),
					   void(*free_fct)(void*))
{
	t_list	*elem;
	t_list	*previous;

	elem = *begin_list;
	while (elem != NULL && !cmp(elem->data, data_ref))
	{
		*begin_list = elem->next;
		free_elem(elem, free_fct);
		elem = elem->next;
	}
	previous = *begin_list;
	while (elem != NULL)
	{
		if (!cmp(elem->data, data_ref))
		{
			previous->next = elem->next;
			free_elem(elem, free_fct);
			elem = previous->next;
		}
		else
		{
			previous = elem;
			elem = elem->next;
		}
	}
}
