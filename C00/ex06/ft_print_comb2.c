#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_print(int a, int b)
{
	if (a < 10)
		ft_putchar('0');
	ft_putnbr(a);
	ft_putchar(' ');
	if (b < 10)
		ft_putchar('0');
	ft_putnbr(b);
	if (a != 98 || b != 99)
		write(1, &", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = -1;
	while (++a < 100)
	{
		b = a;
		while (++b < 100)
		{
			if (a != b)
				ft_print(a, b);
		}
	}
}

int main()
{
	ft_print_comb2();
}
