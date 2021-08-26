#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = begin_list;
	while (elem != NULL)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}
