#include "utils.h"
#include <stdlib.h>

char	*fill_zero(char c, int size)
{
	int		i;
	char	*dest;

	dest = (char *)malloc((size + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	dest[0] = c;
	while (++i < size)
		dest[i] = '0';
	dest[i] = 0;
	return (dest);
}

char	*fill_two_char(char c, char d)
{
	char	*dest;

	dest = (char *)malloc(3 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[0] = c;
	dest[1] = d;
	dest[3] = 0;
	return (dest);
}

int	count_zero(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (i == 0)
		return (1);
	return (i);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
