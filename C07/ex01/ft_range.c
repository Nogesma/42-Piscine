#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (max - min <= 0)
		return (NULL);
	tab = (int *)malloc((max - min) * 4);
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		++i;
	}
	return (tab);
}
