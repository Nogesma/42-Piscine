void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		temp;

	i = 0;
	if (size == 0)
		return ;
	--size;
	while (i != size)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
		--size;
		if (i == size)
			return ;
		++i;
	}
}
