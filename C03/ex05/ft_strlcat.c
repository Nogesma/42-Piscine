unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	r;

	i = 0;
	j = 0;
	while (dest[i])
		++i;
	r = i;
	while (i < size && src[j])
	{
		r++;
		dest[i++] = src[j++];
	}
	i--;
	dest[i] = '\0';
	while (src[j])
	{
		r++;
		j++;
	}
	return (r);
}
