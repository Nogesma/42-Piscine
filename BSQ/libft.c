#include "libft.h"
#include <stdlib.h>
#include "list.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (result);
}

void	free_all(t_map *map, t_point_list **obs, t_solution *solution)
{
	free(map);
	ft_list_clear(*obs);
	free(obs);
	free(solution);
}

int	ft_chr_is_printable(char c)
{
	if (c < ' ')
		return (0);
	if (c > '~')
		return (0);
	return (1);
}

t_point_list	**return_objects(t_point_list **head, t_point_list *pos,
							  t_map *map)
{
	if (map)
		map->is_valid = 0;
	free(pos);
	return (head);
}
