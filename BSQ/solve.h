#ifndef SOLVE_H
# define SOLVE_H

# include "solution.h"
# include "point_list.h"
# include "map.h"

t_solution		*solve(t_point_list *obstacles, t_map *size);

void			look_at(t_point_list *pos, t_solution *solution,
					t_point_list *obstacles, t_map *size);

t_point_list	*find_limiter(t_point_list *pos, t_point_list *obstacles,
					   t_map *size, t_solution solution);

void			update_solution(t_point_list *pos, t_solution *solution,
					t_point_list *limiter, t_map *size);

void			find_set_pos(t_point_list *pos,
					t_point_list *limiter, t_map *size, t_solution sol);

#endif
