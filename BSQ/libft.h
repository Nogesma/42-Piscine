#ifndef LIBFT_H
# define LIBFT_H

# include "map.h"
# include "point_list.h"
# include "solution.h"

int				ft_atoi(const char *str);

void			free_all(t_map *map, t_point_list **obs, t_solution *solution);

int				ft_chr_is_printable(char c);

t_point_list	**return_objects(t_point_list **head, t_point_list *pos,
					  t_map *map);
#endif
