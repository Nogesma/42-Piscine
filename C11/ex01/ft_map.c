//
// Created by Mano Segransan on 8/18/21.
//
#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*dest;

	dest = (int *)malloc(length * sizeof(int *));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		dest[i] = f(tab[i]);
	return (dest);
}
