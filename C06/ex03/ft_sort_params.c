#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		++i;
	}
	if (s1[i] == s2[i])
		return (0);
	return (-s2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i;
	}
}

void	bubble_sort(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < argc - 1)
	{
		while (++j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) < 0)
				ft_swap(&argv[j], &argv[j + 1]);
		}
		j = 0;
	}
}

int	main(int argc, char **argv)
{
	bubble_sort(argc, argv);
	while (--argc > 0)
	{
		ft_putstr(argv[argc]);
		ft_putstr("\n");
	}
}
