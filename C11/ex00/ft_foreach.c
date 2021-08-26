//
// Created by Mano Segransan on 8/18/21.
//

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = -1;
	while (++i < length)
		f(tab[i]);
}
