//
// Created by Mano Segransan on 8/18/21.
//
#include <stdlib.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	sort;
	int	isSortedUp;
	int	isSortedDown;

	i = 0;
	isSortedDown = 1;
	isSortedUp = 1;
	while (++i < length)
	{
		sort = f(tab[i - 1], tab[i]);
		if (sort < 0)
			isSortedUp = 0;
		if (sort > 0)
			isSortedDown = 0;
	}
	return (isSortedUp || isSortedDown);
}
