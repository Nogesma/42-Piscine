#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_display_file(char *fileName)
{
	int		fd;
	char	c;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		return (1);
	while (read(fd, &c, 1))
		ft_putchar(c, 1);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n", 2);
		return (1);
	}
	if (argc != 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (2);
	}
	if (ft_display_file(argv[1]))
	{
		ft_putstr("Cannot read file.\n", 2);
		return (3);
	}
	return (0);
}
