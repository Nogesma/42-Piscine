#include "calculator.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>

int	ft_apply_operation(int i, int j, int(*f)(int, int))
{
	return (f(i, j));
}

void	do_op(int i, int (*func[5])(int, int), char *a, char *b)
{
	int	x;
	int	y;

	x = ft_atoi(a);
	y = ft_atoi(b);
	if (i < 3)
		ft_putnbr(ft_apply_operation(x, y, (*func[i])));
	else
	{
		if (y == 0)
		{
			if (i == 3)
				ft_putstr("Stop : division by zero");
			else
				ft_putstr("Stop : modulo by zero");
		}
		else
			ft_putnbr(ft_apply_operation(x, y, (*func[i])));
	}
}

int	main(int argc, char **argv)
{
	int	(*func[5])(int x, int y);

	func[0] = sum;
	func[1] = subtract;
	func[2] = mul;
	func[3] = div;
	func[4] = mod;
	if (argc == 4)
	{
		if (!ft_strcmp("+", argv[2]))
			do_op(0, func, argv[1], argv[3]);
		else if (!ft_strcmp("-", argv[2]))
			do_op(1, func, argv[1], argv[3]);
		else if (!ft_strcmp("*", argv[2]))
			do_op(2, func, argv[1], argv[3]);
		else if (!ft_strcmp("/", argv[2]))
			do_op(3, func, argv[1], argv[3]);
		else if (!ft_strcmp("%", argv[2]))
			do_op(4, func, argv[1], argv[3]);
		else
			ft_putnbr(0);
		ft_putstr("\n");
	}
}
