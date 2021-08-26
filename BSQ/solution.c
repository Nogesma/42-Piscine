#include "solution.h"
#include <stdlib.h>

t_solution	*init_solution(void)
{
	t_solution	*solution;

	solution = (t_solution *)malloc(sizeof(t_solution));
	if (!solution)
		return (0);
	solution->size = 0;
	solution->x = 0;
	solution->y = 0;
	return (solution);
}

void	set_solution(t_solution *solution, t_point_list *pos, int size)
{
	solution->size = size;
	solution->x = pos->x;
	solution->y = pos->y;
}
