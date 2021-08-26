//
// Created by Mano Segransan on 8/20/21.
//

#include <unistd.h>
#include "print.h"
#include "utils.h"
#include "string.h"
#include "print2.h"
#include <stdlib.h>
#include <sys/errno.h>

void	ft_print_line(long offset, t_string *str, int n, int option)
{
	if (n == 0)
		return ;
	if (ft_strncmp(str->c, str->d, n))
	{
		str->is_star = 0;
		ft_print_input_offset(offset, option);
		ft_putstr(" ", 1);
		if (option)
			ft_putstr(" ", 1);
		ft_print_hex(str->c, n, option);
		if (option)
		{
			ft_putstr("  ", 1);
			ft_print_ascii(str->c, n);
		}
		ft_putchar('\n', 1);
	}
	else
	{
		if (!str->is_star)
		{
			ft_putstr("*\n", 1);
			str->is_star = 1;
		}
	}
}

void	ft_print_error(char *file_name, char *program_name, int error)
{
	if (error)
	{
		ft_putstr(&program_name[2], 2);
		ft_putstr(": ", 2);
		ft_putstr(file_name, 2);
		ft_putstr(": ", 2);
		ft_putstr(strerror(errno), 2);
		ft_putstr("\n", 2);
	}
	else
	{
		ft_putstr(&program_name[2], 2);
		ft_putstr(": ", 2);
		ft_putstr(file_name, 2);
		ft_putstr(": ", 2);
		ft_putstr("Bad file descriptor", 2);
		ft_putstr("\n", 2);
	}
	errno = 0;
}

void	print_stdin(int option)
{
	t_string	*str;
	long		i;
	int			n;

	str = (t_string *)malloc(sizeof(t_string *));
	n = 0;
	i = 0;
	str->is_star = 0;
	while (read(0, &str->c[n++], 1) > 0)
	{
		if (n == 16)
		{
			ft_print_line(i, str, n, option);
			ft_strncpy(str->d, str->c, n);
			i += n;
			n = 0;
		}
	}
	if (n % 16 != 1)
		ft_print_line(i, str, n % 16 - 1, option);
	if (i != 0)
	{
		ft_print_input_offset(i + n - 1, option);
		ft_putchar('\n', 1);
	}
}
