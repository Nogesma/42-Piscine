//
// Created by Mano Segransan on 8/19/21.
//

#include "utils.h"
#include "libft.h"

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	isNegative;

	i = 0;
	isNegative = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isNegative *= -1;
		i++;
	}
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (result * isNegative);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb / 10 != 0)
			ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
