#include "point_list.h"
#include "solution.h"
#include "list.h"
#include "solve.h"
#include <stdlib.h>
#include "map.h"

t_solution	*solve(t_point_list *obstacles, t_map *size)
{
	t_solution		*solution;
	t_point_list	*pos;

	solution = init_solution();
	if (!solution)
		return (0);
	if (!obstacles)
	{
		if (size->x > size->y)
			solution->size = size->y;
		else
			solution->size = size->x;
		return (solution);
	}
	pos = ft_create_elem(0, 0);
	if (!pos)
		return (0);
	while (pos->y < size->y)
	{
		advance_obstacles(&obstacles, pos);
		look_at(pos, solution, obstacles, size);
	}
	free(pos);
	return (solution);
}

void	look_at(t_point_list *pos, t_solution *solution,
			 t_point_list *obstacles, t_map *size)
{
	t_point_list	*limiter;

	limiter = find_limiter(pos, obstacles, size, *solution);
	update_solution(pos, solution, limiter, size);
	find_set_pos(pos, limiter, size, *solution);
}

t_point_list	*find_limiter(t_point_list *pos, t_point_list *obstacles,
							  t_map *size, t_solution solution)
{
	t_point_list	*limiter;
	int				dist;
	int				lim_dist;

	limiter = 0;
	while (obstacles)
	{
		dist = longest_distance_pos(*pos, *obstacles);
		if (dist >= 0)
		{
			if (limiter)
				lim_dist = longest_distance_pos(*pos, *limiter);
			else if ((size->x - pos->x) > (size->y - pos->y))
				lim_dist = (size->y - pos->y);
			else
				lim_dist = (size->x - pos->x);
			if (lim_dist <= solution.size || obstacles->y >= pos->y + lim_dist)
				return (limiter);
			if (dist < lim_dist)
				limiter = obstacles;
		}
		obstacles = obstacles->next;
	}
	return (limiter);
}

void	update_solution(t_point_list *pos, t_solution *solution,
					 t_point_list *limiter, t_map *size)
{
	int		lim_dist;

	if (limiter != NULL)
		lim_dist = longest_distance_pos(*pos, *limiter);
	else if ((size->x - pos->x) > (size->y - pos->y))
		lim_dist = (size->y - pos->y);
	else
		lim_dist = (size->x - pos->x);
	if (lim_dist > solution->size)
		set_solution(solution, pos, lim_dist);
}

void	find_set_pos(t_point_list *pos, t_point_list *limiter, t_map *size,
				  t_solution sol)
{
	int		lim_y;

	if (!limiter)
		wrap_to(pos, 0, pos->y + 1, size);
	else
	{
		lim_y = limiter->y;
		while (limiter->next
			&& x_distance(limiter, limiter->next, size) <= sol.size + 1)
			limiter = limiter->next;
		wrap_to(pos, limiter->x + 1, pos->y + (limiter->y - lim_y), size);
	}
}
