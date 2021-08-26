#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strchri(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
		{
			return (i);
		}
		++i;
	}
	return (-1);
}

int	ft_baselen(char *base)
{
	int	baselen;

	baselen = 0;
	while (base[baselen] != '\0')
	{
		if (base[baselen] == '+' || base[baselen] == '-')
			return (-1);
		if (ft_strchri(base, base[baselen]) != baselen)
			return (-1);
		++baselen;
	}
	return (baselen);
}

void	ft_putnbr(int nb, char *base, int baselen)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / baselen, base, baselen);
		ft_putchar(base[-(nb % baselen)]);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			ft_putnbr(-nb, base, baselen);
		}
		else
		{
			if (nb / baselen != 0)
				ft_putnbr(nb / baselen, base, baselen);
			ft_putchar(base[nb % baselen]);
		}
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	int		baselen;

	baselen = ft_baselen(base);
	if (baselen < 2)
		return ;
	ft_putnbr(nb, base, baselen);
}
