/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  rush03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  By: mbelarbi <mbelarbi@student.42lausanne.ch>   +#+  +:+       +#+        */
/*      msegrans <msegrans@student.42lausanne.ch> +#+#+#+#+#+   +#+           */
/*      vroch    <vroch@student.42lausanne.ch>         #+#    #+#             */
/*  Created: 2021/08/07 14:34:55                      ###   ########.fr       */
/*  Updated: 2021/08/07 14:34:58                                              */
/* ************************************************************************** */

void	ft_putchar(char c);

void	writeLetters(int x, int y, int countX, int countY)
{
	if (countY == 1 || countY == y)
	{
		if (countX == 1)
			ft_putchar('A');
		else if (countX == x)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (countX == 1 || countX == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	countX;
	int	countY;

	countX = 1;
	countY = 1;
	while (countY <= y)
	{
		while (countX <= x)
		{
			writeLetters(x, y, countX, countY);
			countX++;
		}
		countY++;
		countX = 1;
		if (x > 0)
			ft_putchar('\n');
	}
}
