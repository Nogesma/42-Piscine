//
// Created by Mano Segransan on 8/18/21.
//
#include <stdlib.h>

int	ft_any(char **tab, int(*f)(char*))
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		if (f(tab[i]))
			return (1);
	return (0);
}
