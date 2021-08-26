#include "utils.h"
#include <stdlib.h>

void	add_nbr_2(char *str, char **numbers, int *i)
{
	if (str[0] == '1')
	{
		numbers[(*i)++] = fill_two_char(str[0], str[1]);
		str[1] = '0';
	}
	else if (str[0] != '0')
		numbers[(*i)++] = fill_zero(str[0], 2);
}

void	split_nbr_rec(char **numbers, int i, char *str, int len)
{
	if (len < 1)
	{
		numbers[i] = NULL;
		return ;
	}
	if (len % 3 == 0)
	{
		if (str[0] != '0')
			numbers[i++] = fill_zero(str[0], 1);
		if (str[0] != '0')
			numbers[i++] = fill_zero('1', 3);
		return (split_nbr_rec(numbers, i, &str[1], len - 1));
	}
	else if (len % 3 == 1)
	{
		if (str[0] != '0')
			numbers[i++] = fill_zero(str[0], 1);
		if (len != 1)
			numbers[i++] = fill_zero('1', len);
		return (split_nbr_rec(numbers, i, &str[count_zero(&str[1])],
				len - count_zero(&str[1])));
	}
	add_nbr_2(str, numbers, &i);
	split_nbr_rec(numbers, i, &str[1], len - 1);
}

char	**split_nbr(char *str, int len)
{
	char	**numbers;
	char	*zero;

	numbers = (char **)malloc(len * 2 * sizeof(char *));
	if (numbers == NULL)
		return (NULL);
	if (str[0] == '0' && str[1] == 0)
	{
		zero = (char *)malloc(2);
		if (zero == NULL)
			return (NULL);
		zero[0] = '0';
		zero[1] = 0;
		numbers[0] = zero;
		numbers[1] = NULL;
	}
	else
		split_nbr_rec(numbers, 0, str, len);
	return (numbers);
}
