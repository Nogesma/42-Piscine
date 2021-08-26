#include "parsing.h"
#include "list.h"
#include "map.h"
#include <unistd.h>
#include <stdlib.h>

void	get_first_line(t_map *map, int fd, t_point_list **elem,
					t_point_list *pos)
{
	char			c;

	c = 0;
	pos->x = 0;
	pos->y = 0;
	while (c != '\n' && read(fd, &c, 1) > 0)
	{
		if (c != map->empty)
		{
			if (c == map->obstacle)
			{
				(*elem)->next = ft_create_elem(pos->x, pos->y);
				*elem = (*elem)->next;
			}
			else if (c != '\n')
				map->is_valid = 0;
		}
		++pos->x;
	}
	map->x = pos->x - 1;
	++pos->y;
	pos->x = 0;
}

int	add_obstacles(t_map *map, char c, t_point_list **elem,
				t_point_list *pos)
{
	if (pos->x > map->x)
		return (1);
	if (c != map->empty)
	{
		if (c == '\n')
		{
			++pos->y;
			if (pos->x != map->x || pos->y > map->y)
				return (1);
			pos->x = -1;
		}
		else if (c == map->obstacle)
		{
			(*elem)->next = ft_create_elem(pos->x, pos->y);
			*elem = (*elem)->next;
		}
		else
			return (1);
	}
	++pos->x;
	return (0);
}

int	get_all_obstacles(t_map *map, const char *str, t_point_list **elem,
					   t_point_list *pos)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (add_obstacles(map, str[i], elem, pos))
			return (1);
	}
	return (0);
}

int	get_all_obstacles_stdin(t_map *map, int fd, t_point_list **elem,
							 t_point_list *pos)
{
	char	c;

	while (read(fd, &c, 1) > 0)
	{
		if (add_obstacles(map, c, elem, pos))
			return (1);
	}
	return (0);
}

int	get_obstacles(t_map *map, int fd, t_point_list *elem, t_point_list *pos)
{
	int		i;
	char	*str;

	if (fd != 0)
	{
		i = (map->x + 1) * (map->y - 1);
		str = (char *)malloc(i * sizeof(char));
		if (!str)
			return (1);
		if (read(fd, str, i + 1) != i)
		{
			free(str);
			return (1);
		}
		str[i] = 0;
		i = get_all_obstacles(map, str, &elem, pos);
		free(str);
		if (i)
			return (1);
	}
	else
		if (get_all_obstacles_stdin(map, fd, &elem, pos))
			return (1);
	return (0);
}
