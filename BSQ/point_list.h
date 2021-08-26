#ifndef POINT_LIST_H
# define POINT_LIST_H

# include "map.h"

typedef struct s_point_list
{
	int					x;
	int					y;
	struct s_point_list	*next;
}	t_point_list;

int	x_distance(t_point_list *a, t_point_list *b, t_map *size);

#endif
