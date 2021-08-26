#ifndef PARSING_H
# define PARSING_H

# include "map.h"
# include "point_list.h"

int		get_obstacles(t_map *map, int fd, t_point_list *elem,
			   t_point_list *pos);

void	get_first_line(t_map *map, int fd, t_point_list **elem,
			   t_point_list *pos);

#endif //PARSING_H
