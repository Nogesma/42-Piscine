#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>

int	ft_display_file(char *fileName)
{
	int		fd;
	char	c;

	fd = open(fileName, O_RDONLY);
	if (errno)
		return (1);
	while (read(fd, &c, 1) > 0)
		ft_putchar(c, 1);
	if (errno)
		return (1);
	close(fd);
	return (0);
}

void	ft_put_error(char **argv, int i)
{
	ft_putstr(&(argv[0])[2], 2);
	ft_putstr(": ", 2);
	ft_putstr(argv[i], 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
	errno = 0;
}

int	main(int argc, char **argv)
{
	int		i;
	int		return_code;
	char	c;

	if (argc == 1)
		while (read(0, &c, 1) > 0)
			ft_putchar(c, 1);
	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp("-", argv[i]))
			while (read(0, &c, 1) > 0)
				ft_putchar(c, 1);
		else if (ft_display_file(argv[i]))
		{
			return_code = 1;
			ft_put_error(argv, i);
		}
	}
	return (return_code);
}
