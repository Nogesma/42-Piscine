#include <unistd.h>
#include "utils.h"
#include "globals.h"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		++i;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

void	print_grid(const int *grid)
{
	int	i;

	i = -1;
	while (grid[++i] != -1)
	{
		ft_putchar(grid[i] + '0');
		if ((i + 1) % g_gridSize)
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
}

void	getCount(int gridJ, int *count, int *max)
{
	if (gridJ > *max)
	{
		*max = gridJ;
		*count = *count + 1;
	}
}
