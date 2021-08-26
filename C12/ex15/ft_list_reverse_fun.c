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

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*x;
	t_list	*y;
	int		size;
	int		i;
	void	*data;

	x = begin_list;
	y = NULL;
	size = ft_list_size(begin_list);
	while (x != y)
	{
		y = begin_list;
		i = 0;
		while (++i < size)
			y = y->next;
		size--;
		if (x == y)
			return ;
		data = x->data;
		x->data = y->data;
		y->data = data;
		if (x->next)
			x = x->next;
	}
}
