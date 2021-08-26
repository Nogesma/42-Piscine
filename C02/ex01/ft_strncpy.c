char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			terminated;

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
