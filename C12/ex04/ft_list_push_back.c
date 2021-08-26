#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	elem = *begin_list;
	while (elem->next != NULL)
		elem = elem->next;
	elem->next = ft_create_elem(data);
}
