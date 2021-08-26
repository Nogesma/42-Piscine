#include <stdlib.h>

int	ft_strchri(const char *str, char to_find)
{
	int	i;

	if (!to_find)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == to_find)
			return (1);
	return (0);
}

char	*ft_strdup(unsigned int n, const char *src)
{
	unsigned int	i;
	char			terminated;
	char			*dest;

	dest = (char *) malloc((n + 1) * sizeof(char));
	if (dest == NULL)
		return (0);
	i = 0;
	while (i <= n)
		dest[i++] = 0;
	terminated = 0;
	i = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			terminated = 1;
		if (terminated)
			dest[i] = '\0';
		else
			dest[i] = src[i];
		++i;
	}
	return (dest);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	size;
	int	bool;

	i = 0;
	size = 0;
	while (str[i + 1])
	{
		bool = ft_strchri(charset, str[i++]);
		if (bool && !ft_strchri(charset, str[i]))
			size++;
	}
	if (ft_strchri(charset, str[0]))
		return (size);
	return (size + 1);
}

char	**newStr(char **dest, char *str, char *charset)
{
	int	i;
	int	j;
	int	from;

	i = 0;
	while (ft_strchri(charset, str[i++]))
		;
	from = i - 1;
	j = 0;
	while (str[i - 1])
	{
		if (!str[i] && !ft_strchri(charset, str[i - 1]))
			dest[j++] = ft_strdup(i - from, str + from);
		if (ft_strchri(charset, str[i]))
		{
			if (!ft_strchri(charset, str[i - 1]))
				dest[j++] = ft_strdup(i - from, str + from);
			from = i + 1;
		}
		i++;
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		size;
	int		i;

	size = ft_count(str, charset);
	dest = malloc((size + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
		dest[i++] = 0;
	dest = newStr(dest, str, charset);
	return (dest);
}
