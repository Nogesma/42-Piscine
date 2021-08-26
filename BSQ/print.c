#include "print.h"
#include <stdlib.h>
#include <unistd.h>

int	is_square(int i, int j, t_solution *solution)
{
	return (i >= solution->x && j >= solution->y
		&& i - solution->x < solution->size
		&& j - solution->y < solution->size);
}

char	get_solved_char(t_map *map, t_point_list **obs, t_solution *solution,
					   t_point_list *pos)
{
	if (*obs && (*obs)->x == pos->x && (*obs)->y == pos->y)
	{
		*obs = (*obs)->next;
		return (map->obstacle);
	}
	else if (is_square(pos->x, pos->y, solution))
		return (map->square);
	else
		return (map->empty);
}

void	print_solution(t_map *map, t_point_list *obs, t_solution *solution)
{
	int				k;
	t_point_list	*pos;
	char			*solved_map;

	solved_map = (char *)malloc((map->y) * (map->x + 1) * sizeof(char));
	pos = (t_point_list *)malloc(sizeof(t_point_list));
	if (!solved_map || !pos)
		return ;
	pos->y = -1;
	k = 0;
	while (++pos->y < map->y)
	{
		pos->x = -1;
		while (++pos->x < map->x)
			solved_map[k++] = get_solved_char(map, &obs, solution, pos);
		solved_map[k++] = '\n';
	}
	write(1, solved_map, k);
	free(solved_map);
	free(pos);
}
