#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*elem;

	elem = begin_list;
	i = 0;
	while (i < nbr)
	{
		if (elem == NULL)
			return (NULL);
		elem = elem->next;
		i++;
	}
	return (elem);
}
