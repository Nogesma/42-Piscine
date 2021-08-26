#include <stdio.h>
#include <stdlib.h>

int	ft_strchri(char *str, char to_find)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == to_find)
			return (i);
	return (-1);
}

int	ft_radix(char *base)
{
	int	r;

	r = -1;
	while (base[++r] != '\0')
		if (base[r] == '+' || base[r] == '-' || base[r] == ' '
			|| base[r] == '\n' || base[r] == '\t' || base[r] == '\v'
			|| base[r] == '\f' || base[r] == '\r'
			|| ft_strchri(base, base[r]) != r)
			return (-1);
	if (r < 2)
		return (-1);
	return (r);
}

long	ft_atoi(char *str, char *base, int radix)
{
	long	result;
	int		i;
	int		isNegative;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		   || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	isNegative = 1;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			isNegative *= -1;
	result = 0;
	while (ft_strchri(base, str[i]) != -1)
	{
		result *= radix;
		result += ft_strchri(base, str[i]);
		++i;
	}
	return (result * isNegative);
}

void	ft_putnbr(long nb, char *nbs, char *base, int radix)
{
	int		i;
	int		j;
	int		negative;
	char	*nb_rev;

	nb_rev = (char *) malloc(32);
	negative = 0;
	if (nb < 0)
		negative = 1;
	if (nb < 0)
		nb *= -1;
	i = 0;
	while (nb / radix != 0)
	{
		nb_rev[i++] = base[nb % radix];
		nb /= radix;
	}
	nb_rev[i++] = base[nb % radix];
	if (negative)
		nb_rev[i++] = '-';
	j = -1;
	while (++j <= i - 1)
		nbs[j] = nb_rev[i - 1 - j];
	free(nb_rev);
	nbs[j] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*nb;
	long	nbl;
	int		radix_from;
	int		radix_to;

	radix_from = ft_radix(base_from);
	radix_to = ft_radix(base_to);
	if (radix_from == -1 || radix_to == -1)
		return (NULL);
	nbl = ft_atoi(nbr, base_from, radix_from);
	nb = (char *) malloc(32);
	ft_putnbr(nbl, nb, base_to, radix_to);
	return (nb);
}
