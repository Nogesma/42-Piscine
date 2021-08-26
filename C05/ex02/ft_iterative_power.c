int	ft_iterative_power(int i, int pow)
{
	int	j;

	j = i;
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	while (pow > 1)
	{
		j = j * i;
		--pow;
	}
	return (j);
}
