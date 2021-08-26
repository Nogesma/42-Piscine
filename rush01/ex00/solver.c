#include <stdlib.h>
#include "solver.h"
#include "globals.h"
#include "utils.h"
#include "validation.h"

int	recursive_solver(const int *args, int *grid, int i)
{
	int	num;

	if (i == g_gridCount)
		return (1);
	if (grid[i])
	{
		if (recursive_solver(args, grid, i + 1))
			return (1);
		return (0);
	}
	num = 0;
	while (++num <= g_gridSize)
	{
		if (isValidGrid(num, args, grid, i))
		{
			grid[i] = num;
			if (recursive_solver(args, grid, i + 1))
				return (1);
			grid[i] = 0;
		}
	}
	return (0);
}

void	fillEasyCases(const int *args, int *grid)
{
	int	i;

	i = -1;
	while (++i < g_gridSize)
		if (args[i] == 1)
			grid[i] = g_gridSize;
	while (++i < g_gridSize * 2)
		if (args[i] == 1)
			grid[(g_gridCount - g_gridSize) + i % g_gridSize] = g_gridSize;
	while (++i < g_gridSize * 3)
		if (args[i] == 1)
			grid[i % g_gridSize * g_gridSize] = g_gridSize;
	while (++i < g_gridCount)
		if (args[i] == 1)
			grid[i % g_gridSize * g_gridSize + g_gridSize - 1] = g_gridSize;
}

void	initGrid(int *grid)
{
	int	i;

	i = -1;
	while (++i < g_gridCount)
		grid[i] = 0;
	grid[i] = -1;
}

int	initArgs(int *args, const char *str)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	j = 0;
	while (str[++i])
	{
		n = str[i] - '0';
		if (n >= 1 && n <= g_gridSize)
		{
			args[j] = n;
			j++;
		}
		else if (str[i] != ' ')
			return (0);
		if (j > 4 * g_gridSize)
			return (0);
	}
	args[j] = -1;
	return (1);
}

int	solver(const char *str)
{
	int	*args;
	int	*grid;

	g_gridCount = g_gridSize * g_gridSize;
	args = (int *)malloc((4 * g_gridSize + 1) * sizeof(int));
	if (args == NULL)
		return (0);
	if (!initArgs(args, str))
		return (0);
	grid = (int *)malloc((g_gridCount + 1) * sizeof(int));
	if (grid == NULL)
		return (0);
	initGrid(grid);
	fillEasyCases(args, grid);
	if (!recursive_solver(args, grid, 0))
		return (0);
	print_grid(grid);
	return (1);
}
