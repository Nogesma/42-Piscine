#ifndef SOLUTION_H
# define SOLUTION_H

# include "point_list.h"

typedef struct s_solution
{
	int		size;
	int		x;
	int		y;
}	t_solution;

t_solution	*init_solution(void);

void		set_solution(t_solution *solution, t_point_list *pos, int size);

#endif
