//
// Created by Mano Segransan on 8/20/21.
//
#include "list.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_list	*ft_create_elem(char c)
{
	t_list	*elem;

	elem = (struct s_t_list *)malloc(sizeof(t_list));
	elem->c = c;
	elem->next = NULL;
	return (elem);
}

void	ft_print_stdin(int count, int n, t_list *begin_list)
{
	int		i;
	t_list	*temp;

	i = 0;
	n = count - n;
	while (i < count)
	{
		temp = begin_list;
		if (i >= n)
			ft_putchar(begin_list->c, 1);
		begin_list = begin_list->next;
		free(temp);
		i++;
	}
}

void	ft_create_list(int n)
{
	char	c;
	t_list	*begin_list;
	t_list	*elem;
	int		count;

	count = 0;
	if (read(0, &c, 1) > 0)
	{
		elem = ft_create_elem(c);
		begin_list = elem;
		count++;
	}
	while (read(0, &c, 1) > 0)
	{
		elem->next = ft_create_elem(c);
		elem = elem->next;
		count++;
	}
	ft_print_stdin(count, n, begin_list);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (result);
}
