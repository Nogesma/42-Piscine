#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*elem;

	elem = begin_list;
	while (elem->next != NULL)
		elem = elem->next;
	return (elem);
}
