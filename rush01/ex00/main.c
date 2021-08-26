#include "globals.h"
#include "utils.h"
#include "solver.h"

int	main(int argc, char **argv)
{
	int	size;
	int	notError;

	notError = 1;
	if (argc != 2)
		notError = 0;
	if (notError)
	{
		size = ft_strlen(argv[1]) / 2 + 1;
		g_gridSize = size / 4;
		if (g_gridSize < 4 || g_gridSize > 9 || size % 4 != 0)
			notError = 0;
		if (notError)
			notError = solver(argv[1]);
	}
	if (!notError)
		ft_putstr("Error\n");
}
