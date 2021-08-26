#include <unistd.h>

int	isValidDiag(const int *grid, int i)
{
	int	y;
	int	x;

	y = -1;
	x = i % 10 - i / 10 - 1;
	while (++y < 10 && ++x < 10)
		if (x >= 0)
			if (grid[y * 10 + x])
				return (0);
	y = -1;
	x = i % 10 + i / 10 + 1;
	while (++y < 10 && --x >= 0)
		if (x < 10)
			if (grid[y * 10 + x])
				return (0);
	return (1);
}

int	isValidGrid(const int *grid, int i)
{
	int	j;
	int	temp;

	j = i % 10;
	while (j < 100)
	{
		if (grid[j] == 1)
			return (0);
		j += 10;
	}
	j = i / 10 * 10;
	temp = j + 10;
	while (j < temp)
		if (grid[j++] == 1)
			return (0);
	if (!isValidDiag(grid, i))
		return (0);
	return (1);
}

void	print_grid(const int *grid)
{
	int		i;
	char	c;

	i = -1;
	while (grid[++i] != -1)
	{
		if (grid[i])
		{
			c = i % 10 + '0';
			write(1, &c, 1);
		}
	}
	write(1, "\n", 1);
}

int	recursive_solver(int *grid, int i, int *solutions)
{
	if (i == 100)
	{
		print_grid(grid);
		(*solutions)++;
		i--;
		grid[i] = 0;
		return (0);
	}
	if (isValidGrid(grid, i))
	{
		grid[i] = 1;
		if (recursive_solver(grid, i / 10 * 10 + 10, solutions))
			return (1);
		grid[i] = 0;
	}
	if (i % 10 != 9)
		return (recursive_solver(grid, i + 1, solutions));
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	grid[101];
	int	solutions;
	int	i;

	i = -1;
	while (++i < 100)
		grid[i] = 0;
	grid[i] = -1;
	solutions = 0;
	recursive_solver(grid, 0, &solutions);
	return (solutions);
}
