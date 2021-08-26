#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach(t_list *begin_list, void(*f)(void*))
{
	t_list	*elem;

	elem = begin_list;
	while (elem != NULL)
	{
		f(elem->data);
		elem = elem->next;
	}
}
