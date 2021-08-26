//
// Created by Mano Segransan on 8/19/21.
//
#include <stdlib.h>

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	bubble_sort(int argc, char **argv, int(*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < argc - 1)
	{
		while (++j < argc - 1)
		{
			if (cmp(argv[j], argv[j + 1]) > 0)
				ft_swap(&argv[j], &argv[j + 1]);
		}
		j = -1;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		++len;
	bubble_sort(len, tab, cmp);
}
