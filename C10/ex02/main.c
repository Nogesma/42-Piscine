#include "libft.h"
#include "list.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>

void	ft_print_filename(char *file_name, int display_file_name, int new_line)
{
	if (display_file_name)
	{
		if (new_line)
			ft_putstr("\n", 1);
		ft_putstr("==> ", 1);
		ft_putstr(file_name, 1);
		ft_putstr(" <==\n", 1);
	}
}

int	ft_display_file(int n, char *file_name, int display_file_name, int new_line)
{
	int		fd;
	int		i;
	char	c;

	fd = open(file_name, O_RDONLY);
	if (errno)
		return (1);
	i = 0;
	while (read(fd, &c, 1) > 0)
		++i;
	close(fd);
	n = i - n;
	i = 0;
	ft_print_filename(file_name, display_file_name, new_line);
	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (i >= n)
			ft_putchar(c, 1);
		i++;
	}
	close(fd);
	if (errno)
		errno = 0;
	return (0);
}

void	ft_print_error(char *file_name, char *prog_name)
{
	ft_putstr(&prog_name[2], 2);
	ft_putstr(": ", 2);
	ft_putstr(file_name, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
	errno = 0;
}

void	ft_loop(int argc, char **argv, int n)
{
	int	i;
	int	j;

	j = 3;
	i = 2;
	while (++i < argc)
	{
		if (ft_display_file(n, argv[i], argc > 4, i != j))
		{
			j++;
			ft_print_error(argv[i], argv[0]);
		}
	}
}

int	main(int argc, char **argv)
{
	int		n;

	if (argc == 2)
		return (1);
	if (argc > 2)
	{
		n = ft_atoi(argv[2]);
		if (n == -1)
		{
			ft_putstr(&(argv[0])[2], 2);
			ft_putstr(": illegal offset -- ", 2);
			ft_putstr(argv[2], 2);
			ft_putstr("\n", 2);
			return (1);
		}
		if (argc == 3)
			ft_create_list(n);
		else if (argc > 3)
			ft_loop(argc, argv, n);
	}
	return (0);
}
