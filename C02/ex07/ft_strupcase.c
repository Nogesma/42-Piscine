char	*ft_strupcase(char *str)
{
	int		i;
	char	temp;

	i = 0;
	while (str[i] != '\0')
	{
		temp = str[i];
		if (temp >= 'a' && temp <= 'z')
			str[i] = temp - 32;
		else
			str[i] = temp;
		++i;
	}
	return (str);
}
