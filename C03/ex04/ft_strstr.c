char	*loop(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	int				f;

	i = 0;
	j = 0;
	f = -1;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j++])
		{
			if (f == -1)
				f = i;
			if (to_find[j] == '\0')
				return (&str[f]);
		}
		else
		{
			f = -1;
			j = 0;
		}
		++i;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (to_find[0] == '\0')
		return (str);
	return (loop(str, to_find));
}
