//
// Created by Mano Segransan on 8/19/21.
//
#include <unistd.h>
#include <stdlib.h>
#include "print.h"
#include "utils.h"

void	ft_putchar(unsigned char c, int i)
{
	write(i, &c, 1);
}

void	ft_putstr(char *str, int j)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i], j);
}

void	ft_print_ascii(const unsigned char *str, int n)
{
	int	i;

	i = 0;
	ft_putchar('|', 1);
	while (i < n)
	{
		if (ft_chr_is_printable(str[i]))
			ft_putchar(str[i], 1);
		else
			ft_putchar('.', 1);
		++i;
	}
	ft_putchar('|', 1);
}

void	ft_print_input_offset(long i, int option)
{
	char	*c;
	int		size;

	if (option)
		size = 9;
	else
		size = 8;
	c = (char *)malloc(size * sizeof(char *));
	if (c == NULL)
		return ;
	ft_getnbr_hex(i, c, size - 1);
	ft_putstr(c, 1);
}

void	ft_print_hex(const unsigned char *str, int n, int option)
{
	int		i;
	char	*c;

	c = (char *)malloc(3 * sizeof(char *));
	if (c == NULL)
		return ;
	i = 0;
	while (i < 16)
	{
		if (i >= n)
			ft_putstr("  ", 1);
		else
		{
			ft_getnbr_hex(str[i], c, 2);
			ft_putstr(c, 1);
		}
		if (i != 15)
			ft_putchar(' ', 1);
		if (i == 7 && option)
			ft_putchar(' ', 1);
		++i;
	}
}
