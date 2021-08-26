#include "libft.h"
#include "dict.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_atoa(argv[1]);
		if (argv[1][0] == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
		parse_dict(argv[1], "./numbers.dict");
	}
	else if (argc == 3)
	{
		ft_atoa(argv[2]);
		if (argv[2][0] == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
		parse_dict(argv[2], argv[1]);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
