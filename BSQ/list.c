#include "list.h"
#include <stdlib.h>

t_point_list	*ft_create_elem(int x, int y)
{
	t_point_list	*elem;

	elem = (t_point_list *)malloc(sizeof(t_point_list));
	if (!elem)
		return (NULL);
	elem->x = x;
	elem->y = y;
	elem->next = NULL;
	return (elem);
}

int	longest_distance_pos(t_point_list pos1, t_point_list pos2)
{
	if ((pos2.x - pos1.x) < 0)
		return (-1);
	if ((pos2.y - pos1.y) < 0)
		return (-1);
	if ((pos2.x - pos1.x) >= (pos2.y - pos1.y))
		return (pos2.x - pos1.x);
	return (pos2.y - pos1.y);
}

void	wrap_to(t_point_list *point, int x, int y, t_map *size)
{
	point->x = x % size->x;
	if (x >= size->x)
		point->y = y + 1;
	else
		point->y = y;
}

void	advance_obstacles(t_point_list **obstacles, t_point_list *pos)
{
	while ((*obstacles)->y < pos->y && (*obstacles)->next)
		*obstacles = (*obstacles)->next;
}

void	ft_list_clear(t_point_list *begin_list)
{
	t_point_list	*elem;

	while (begin_list != NULL)
	{
		elem = begin_list;
		begin_list = begin_list->next;
		free(elem);
	}
}
