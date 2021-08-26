int	ft_recursive_power(int i, int pow)
{
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	return (i * ft_recursive_power(i, pow - 1));
}
