#include "parsing.h"
#include <stdlib.h>

void	linked_to_string(t_list *head, char *dest)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = head;
	while (elem != NULL)
	{
		dest[i++] = elem->c;
		elem = elem->next;
	}
	dest[i] = 0;
}

int	check_start_string(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
	{
		str[0] = 0;
		return (-1);
	}
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '.')
	{
		str[0] = 0;
		return (-1);
	}
	if (str[i - 1] == '0' && (str[i] < '0' || str[i] > '9'))
	{
		str[0] = '0';
		str[1] = 0;
		return (-1);
	}
	return (i);
}

void	ft_atoa(char *str)
{
	int	i;
	int	j;

	i = check_start_string(str);
	if (i == -1)
		return ;
	j = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == '.')
			{
				str[0] = 0;
				return ;
			}
			str[j] = 0;
			return ;
		}
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = 0;
}
