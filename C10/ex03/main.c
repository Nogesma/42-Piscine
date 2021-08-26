#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>
#include "print.h"
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "print2.h"

int	get_file_descriptor(int *j, char **file_list, int *bad_fd, int nbr)
{
	int	fd;

	fd = open(file_list[*j], O_RDONLY);
	while (errno && *j < nbr)
	{
		*bad_fd = *bad_fd + 1;
		ft_print_error(file_list[*j], file_list[0], 1);
		close(fd);
		*j = *j + 1;
		errno = 0;
		fd = open(file_list[*j], O_RDONLY);
	}
	return (fd);
}

void	update(long *i, int *n, t_string *str, int fd)
{
	*i = *i + (long)(*n);
	ft_strncpy(str->d, str->c, *n);
	*n = read(fd, &str->c, 16);
}

long	ft_print_file(char **file_list, int *bad_fd, int nbr, int option)
{
	t_string	*str;
	long		i;
	int			j;
	int			fd;
	int			n;

	i = 0;
	j = 1 + option;
	str = (t_string *)malloc(sizeof(t_string *));
	fd = get_file_descriptor(&j, file_list, bad_fd, nbr);
	str->is_star = 0;
	n = read(fd, &str->c, 16);
	while (j < nbr)
	{
		if (n < 16 && ++j < nbr)
		{
			fd = get_file_descriptor(&j, file_list, bad_fd, nbr);
			if (fd > 0)
				n = n + (int)read(fd, &str->c[n], 16 - n);
		}
		ft_print_line(i, str, n, option);
		update(&i, &n, str, fd);
	}
	return (i);
}

void	ft_display_file(char **argv, int argc, int option)
{
	long	i;
	int		bad_fd;

	bad_fd = 0;
	i = ft_print_file(argv, &bad_fd, argc, option);
	if (bad_fd == argc - option - 1)
		ft_print_error(argv[argc - 1], argv[0], 0);
	else if (i != 0)
	{
		ft_print_input_offset(i, option);
		ft_putchar('\n', 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		print_stdin(0);
	if (argc > 1)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == 0)
		{
			if (argc == 2)
				print_stdin(1);
			else
				ft_display_file(argv, argc, 1);
		}
		else
			ft_display_file(argv, argc, 0);
	}
	return (0);
}
