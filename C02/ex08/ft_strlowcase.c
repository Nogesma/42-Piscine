char	*ft_strlowcase(char *str)
{
	int		i;
	char	temp;

	i = 0;
	while (str[i] != '\0')
	{
		temp = str[i];
		if (temp >= 'A' && temp <= 'Z')
			str[i] = temp + 32;
		else
			str[i] = temp;
		++i;
	}
	return (str);
}
