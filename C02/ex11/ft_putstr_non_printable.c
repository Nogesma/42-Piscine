#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_chr_is_printable(char c)
{
	if (c < ' ')
		return (0);
	if (c > '~')
		return (0);
	return (1);
}

void	ft_putnbr_hex(unsigned char nb)
{
	unsigned char	i;
	char			intString[10];

	if (nb == 0)
		ft_putchar('0');
	i = 0;
	while (nb != 0)
	{
		intString[i++] = "0123456789abcdef"[nb % 16];
		nb = nb / 16;
	}
	if (i == 1)
		intString[i++] = '0';
	i--;
	while (i)
	{
		ft_putchar(intString[i--]);
	}
	ft_putchar(intString[i]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_chr_is_printable(str[i]))
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putnbr_hex(str[i]);
		}
		++i;
	}
}
