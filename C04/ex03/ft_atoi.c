int	power(int i, int pow)
{
	int	j;

	j = i;
	if (pow == 0)
		return (1);
	while (pow > 1)
	{
		j = j * i;
		--pow;
	}
	return (j);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	isNegative;

	i = 0;
	while (is_space(str[i]))
		i++;
	isNegative = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isNegative *= -1;
		i++;
	}
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	return (result * isNegative);
}
