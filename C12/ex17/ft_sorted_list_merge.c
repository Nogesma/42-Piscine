#include "ft_list.h"
#include <stdlib.h>

t_list	*merge(t_list *left, t_list *right, int(*cmp)())
{
	t_list	*elem;

	elem = NULL;
	if (left == NULL)
		return (right);
	if (right == NULL)
		return (left);
	if (cmp(left->data, right->data) < 0)
	{
		elem = left;
		elem->next = merge(left->next, right, cmp);
	}
	else
	{
		elem = right;
		elem->next = merge(left, right->next, cmp);
	}
	return (elem);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
						  int(*cmp)())
{
	*begin_list1 = merge(*begin_list1, begin_list2, cmp);
}
