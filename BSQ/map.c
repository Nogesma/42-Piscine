#include "map.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	fill_map(t_map *map, char *str, int i)
{
	map->empty = str[i - 4];
	map->obstacle = str[i - 3];
	map->square = str[i - 2];
	str[i - 4] = 0;
	map->y = ft_atoi(str);
}

t_map	*init_map(int fd)
{
	char	*c;
	int		i;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	c = (char *)malloc(13 * sizeof(char));
	if (!map || !c)
	{
		free(c);
		return (map);
	}
	map->x = 0;
	map->is_valid = 1;
	i = 0;
	if (read(fd, &c[i++], 1) < 1)
	{
		free(c);
		return (map);
	}
	while (c[i - 1] != '\n' && read(fd, &c[i], 1) > 0)
		++i;
	fill_map(map, c, i);
	free(c);
	return (map);
}

int	check_map(t_map *map)
{
	if (!map)
		return (1);
	if (map->empty == map->square
		|| map->empty == map->obstacle
		|| map->square == map->obstacle || map->y == 0
		|| !ft_chr_is_printable(map->empty) || !ft_chr_is_printable(map->square)
		|| !ft_chr_is_printable(map->obstacle))
	{
		free(map);
		return (1);
	}
	return (0);
}
