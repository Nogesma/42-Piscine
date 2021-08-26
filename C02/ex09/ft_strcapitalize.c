int	ft_is_alphanumeric(char c)
{
	if (c < '0')
		return (0);
	if (c > 'z')
		return (0);
	if (c > 'Z' && c < 'a')
		return (0);
	if (c > '9' && c < 'A')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	temp;

	i = 0;
	while (str[i] != '\0')
	{
		temp = str[i];
		if (i == 0 || !ft_is_alphanumeric(str[i - 1]))
		{
			if (temp >= 'a' && temp <= 'z')
				str[i] = temp - 32;
			else
				str[i] = temp;
		}
		else if (temp >= 'A' && temp <= 'Z')
			str[i] = temp + 32;
		else
			str[i] = temp;
		++i;
	}
	return (str);
}
