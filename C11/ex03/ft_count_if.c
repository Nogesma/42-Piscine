//
// Created by Mano Segransan on 8/18/21.
//
#include <stdlib.h>

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (++i < length)
		if (f(tab[i]))
			n++;
	return (n);
}
