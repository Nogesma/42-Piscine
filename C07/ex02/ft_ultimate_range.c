#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	tab = (int *)malloc((max - min) * 4);
	if (tab == NULL)
		return (tab);
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		++i;
	}
	return (tab);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	long	diff;

	diff = (long)max - (long)min;
	if (diff <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_range(min, max);
	if (range == NULL)
		return (-1);
	return (diff);
}
