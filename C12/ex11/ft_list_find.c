#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_find(t_list *begin_list, void*data_ref, int(*cmp)())
{
	while (begin_list != NULL && cmp(begin_list->data, data_ref))
		begin_list = begin_list->next;
	return (begin_list);
}
