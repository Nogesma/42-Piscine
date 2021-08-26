#include <unistd.h>
#include "parsing.h"
#include "point_list.h"
#include <fcntl.h>
#include <stdlib.h>
#include "list.h"
#include "print.h"
#include "solve.h"
#include "libft.h"
#include "solution.h"

t_point_list	**init_map_obstacles(t_map *map, int fd)
{
	t_point_list	*pos;
	t_point_list	**head;
	t_point_list	*elem;

	head = (t_point_list **)malloc(sizeof(t_point_list *));
	pos = (t_point_list *)malloc(sizeof(t_point_list));
	if (!head || !pos)
		return (return_objects(head, pos, map));
	elem = ft_create_elem(-1, -1);
	*head = elem;
	get_first_line(map, fd, &elem, pos);
	if (map->x == 0)
		return (return_objects(head, pos, map));
	if (get_obstacles(map, fd, elem, pos))
		return (return_objects(head, pos, map));
	return (return_objects(head, pos, NULL));
}

int	parse_map(const char *file_name)
{
	int				fd;
	t_map			*map;
	t_point_list	**head;
	t_solution		*solution;

	fd = open(file_name, O_RDONLY);
	if (!file_name)
		fd = 0;
	if (fd < 0)
		return (1);
	map = init_map(fd);
	if (check_map(map))
		return (1);
	head = init_map_obstacles(map, fd);
	if (!map->is_valid)
	{
		free_all(map, head, NULL);
		return (1);
	}
	if (close(fd) < 0)
		return (1);
	solution = solve((*head)->next, map);
	print_solution(map, (*head)->next, solution);
	free_all(map, head, solution);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		if (parse_map(0))
			write(2, "map error\n", 10);
	}
	else if (argc > 1)
	{
		while (++i < argc)
		{
			if (parse_map(argv[i]))
				write(2, "map error\n", 10);
			if (i != argc - 1)
				write(1, &"\n", 1);
		}
	}
}
