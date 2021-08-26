#include "point_list.h"
#include "map.h"

//use only with b further on list than a
int	x_distance(t_point_list *a, t_point_list *b, t_map *size)
{
	int		x;

	x = (b->x + (b->y - a->y) * size->x) - a->x;
	return (x);
}
