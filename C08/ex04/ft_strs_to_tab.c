#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int			i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(int size, char *src)
{
	char	*dest;

	dest = (char *) malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	return (ft_strcpy(dest, src));
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*s;
	int					i;
	int					size;

	i = 0;
	if (ac <= 0)
		s = malloc(1 * sizeof(struct s_stock_str));
	else
	{
		s = malloc((ac + 1) * sizeof(struct s_stock_str));
		if (s == NULL)
			return (NULL);
		while (i < ac)
		{
			size = ft_strlen(av[i]);
			s[i].str = av[i];
			s[i].size = size;
			s[i].copy = ft_strdup(size, av[i]);
			i++;
		}
	}
	s[i].str = 0;
	s[i].size = 0;
	s[i].copy = 0;
	return (s);
}
