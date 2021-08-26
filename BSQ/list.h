#ifndef LIST_H
# define LIST_H

# include "point_list.h"

t_point_list	*ft_create_elem(int x, int y);

int				longest_distance_pos(t_point_list pos1, t_point_list pos2);

void			wrap_to(t_point_list *point, int x, int y, t_map *size);

void			advance_obstacles(t_point_list **obstacles, t_point_list *pos);

void			ft_list_clear(t_point_list *begin_list);

#endif //LIST_H
