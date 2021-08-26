char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	while (j < nb)
	{
		dest[i] = src[j];
		if (src[j] == '\0')
			return (dest);
		++i;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
