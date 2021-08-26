#include "globals.h"
#include "validation.h"
#include "utils.h"

int	isValidColUp(const int *grid, int num, int i, int value)
{
	int	j;
	int	count;
	int	max;

	max = 0;
	count = 0;
	j = i % g_gridSize;
	while (j < g_gridCount)
	{
		if (i == j)
			getCount(num, &count, &max);
		else
		{
			if (grid[j] == 0)
				return (1);
			getCount(grid[j], &count, &max);
		}
		if (count > value)
			return (0);
		j += g_gridSize;
	}
	return (count == value);
}

int	isValidColDown(const int *grid, int num, int i, int value)
{
	int	j;
	int	count;
	int	max;

	max = 0;
	count = 0;
	j = i % g_gridSize + (g_gridCount - g_gridSize);
	while (j >= 0)
	{
		if (i == j)
			getCount(num, &count, &max);
		else
		{
			if (grid[j] == 0)
				return (1);
			getCount(grid[j], &count, &max);
		}
		if (count > value)
			return (0);
		j -= g_gridSize;
	}
	return (count == value);
}

int	isValidRowLeft(const int *grid, int num, int i, int value)
{
	int	j;
	int	temp;
	int	count;
	int	max;

	max = 0;
	count = 0;
	j = i / g_gridSize * g_gridSize;
	temp = j + g_gridSize;
	while (j < temp)
	{
		if (i == j)
			getCount(num, &count, &max);
		else
		{
			if (grid[j] == 0)
				return (1);
			getCount(grid[j], &count, &max);
		}
		if (count > value)
			return (0);
		j++;
	}
	return (count == value);
}

int	isValidRowRight(const int *grid, int num, int i, int value)
{
	int	j;
	int	temp;
	int	count;
	int	max;

	max = 0;
	count = 0;
	temp = i / g_gridSize * g_gridSize;
	j = temp + g_gridSize - 1;
	while (j >= temp)
	{
		if (i == j)
			getCount(num, &count, &max);
		else
		{
			if (grid[j] == 0)
				return (1);
			getCount(grid[j], &count, &max);
		}
		if (count > value)
			return (0);
		j--;
	}
	return (count == value);
}

int	isValidGrid(int num, const int *args, const int *grid, int i)
{
	int	j;
	int	temp;

	j = i % g_gridSize;
	while (j < g_gridCount)
	{
		if (grid[j] == num)
			return (0);
		j += g_gridSize;
	}
	j = i / g_gridSize * g_gridSize;
	temp = j + g_gridSize;
	while (j < temp)
		if (grid[j++] == num)
			return (0);
	if (!isValidRowLeft(grid, num, i, args[g_gridSize * 2 + i / g_gridSize]))
		return (0);
	if (!isValidRowRight(grid, num, i, args[g_gridSize * 3 + i / g_gridSize]))
		return (0);
	if (!isValidColDown(grid, num, i, args[g_gridSize + i % g_gridSize]))
		return (0);
	if (!isValidColUp(grid, num, i, args[i % g_gridSize]))
		return (0);
	return (1);
}
