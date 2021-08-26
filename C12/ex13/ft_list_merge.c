#include "ft_list.h"
#include <stdlib.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*elem;

	elem = *begin_list1;
	if (elem == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (elem->next != NULL)
		elem = elem->next;
	elem->next = begin_list2;
}
