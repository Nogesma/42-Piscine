#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	elem->next = *begin_list;
	*begin_list = elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin_list;

	i = -1;
	begin_list = NULL;
	while (++i < size)
		ft_list_push_front(&begin_list, strs[i]);
	return (begin_list);
}
