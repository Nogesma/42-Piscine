int	ft_sqrt(int nb)
{
	long	i;
	long	p;

	i = 0;
	p = 0;
	while (p <= nb)
	{
		if (p == nb)
			return (i);
		++i;
		p = i * i;
	}
	return (0);
}
