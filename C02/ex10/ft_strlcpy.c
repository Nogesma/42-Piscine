unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0 && src[0])
	{
		while (i < size && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		i--;
	}
	dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}
