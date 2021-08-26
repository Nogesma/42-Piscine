#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int		x;
	int		y;
	char	empty;
	char	obstacle;
	char	square;
	int		is_valid;
}	t_map;

t_map	*init_map(int fd);

int		check_map(t_map *map);

#endif //MAP_H
