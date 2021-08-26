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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		++i;
	}
	if (s1[i] == s2[i])
		return (0);
	return (-s2[i]);
}

void	bubble_sort(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < argc - 1)
	{
		while (++j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_swap(&argv[j], &argv[j + 1]);
		}
		j = -1;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		++len;
	bubble_sort(len, tab);
}
