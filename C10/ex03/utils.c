//
// Created by Mano Segransan on 8/19/21.
//

#include "utils.h"
#include <stdlib.h>

int	ft_chr_is_printable(unsigned char c)
{
	if (c < ' ')
		return (0);
	if (c > '~')
		return (0);
	return (1);
}

void	ft_strncpy(unsigned char *dest, const unsigned char *src,
				unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n)
		dest[i] = src[i];
	dest[i] = 0;
}

void	ft_getnbr_hex(long nb, char *nbs, int size)
{
	int		i;
	int		j;
	char	*nb_rev;

	nb_rev = (char *) malloc(size * sizeof(char));
	if (nb_rev == NULL)
		return ;
	i = 0;
	while (i < size)
		nb_rev[i++] = '0';
	i = 0;
	while (nb / 16 != 0)
	{
		nb_rev[i++] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	nb_rev[i] = "0123456789abcdef"[nb % 16];
	j = -1;
	while (++j < size)
		nbs[j] = nb_rev[size - 1 - j];
	nbs[j] = '\0';
}

int	ft_strncmp(unsigned char *s1, unsigned char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		++i;
	}
	--i;
	if (s1[i] == s2[i])
		return (0);
	return (1);
}
