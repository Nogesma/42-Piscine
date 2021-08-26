#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach_if(t_list *begin_list, void(*f)(void*),
						void*data_ref, int(*cmp)())
{
	t_list	*elem;

	elem = begin_list;
	while (elem != NULL)
	{
		if (!cmp(elem->data, data_ref))
			f(elem->data);
		elem = elem->next;
	}
}
