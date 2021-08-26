#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	current = *begin_list;
	next = current;
	previous = NULL;
	while (current != NULL)
	{
		next = next->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}
