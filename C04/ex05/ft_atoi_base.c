int	ft_strchri(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
		{
			return (i);
		}
		++i;
	}
	return (-1);
}

int	ft_baselen(char *base)
{
	int	baselen;

	baselen = 0;
	while (base[baselen] != '\0')
	{
		if (base[baselen] == '+' || base[baselen] == '-'
			|| base[baselen] == ' ')
			return (-1);
		if (ft_strchri(base, base[baselen]) != baselen)
			return (-1);
		++baselen;
	}
	return (baselen);
}

int	get_result(int i, char *base, int isNegative, char *str)
{
	int	result;
	int	baselen;

	baselen = ft_baselen(base);
	if (baselen < 2)
		return (0);
	result = 0;
	while (ft_strchri(base, str[i]) != -1)
	{
		result *= baselen;
		result += ft_strchri(base, str[i]);
		++i;
	}
	return (result * isNegative);
}

int	ft_atoi_base(char *str, char *base)
{
	int	start;
	int	isNegative;

	start = 0;
	while (str[start] == ' ' || str[start] == '\n' || str[start] == '\t'
		   || str[start] == '\v' || str[start] == '\f' || str[start] == '\r')
		start++;
	isNegative = 1;
	while (str[start] == '+' || str[start] == '-')
	{
		if (str[start] == '-')
			isNegative *= -1;
		start++;
	}
	return (get_result(start, base, isNegative, str));
}
