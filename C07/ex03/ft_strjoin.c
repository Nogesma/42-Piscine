#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

int	ft_strcpy(char *dest, char *src)
{
	int			i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str;

	if (size <= 0)
		str = (char *) malloc(0);
	if (size <= 0)
		return (str);
	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	str = (char *) malloc((size - 1) * ft_strlen(sep) + len + 1);
	i = 0;
	while (i <= (size - 1) * ft_strlen(sep) + len + 1)
		str[i++] = 0;
	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strcpy(&str[len], strs[i++]);
		if (i != size)
			len += ft_strcpy(&str[len], sep);
	}
	return (str);
}
