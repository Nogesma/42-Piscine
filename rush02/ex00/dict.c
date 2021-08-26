#include "dict.h"
#include "numbers.h"
#include "parsing.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_get_dict_nbr(int fd)
{
	int		i;
	char	c;
	char	*dest;
	t_list	*head;

	head = NULL;
	if (read(fd, &c, 1) < 1)
		return (NULL);
	ft_list_push_back(&head, c);
	i = 1;
	while (c != ':' && c != '\n')
	{
		if (read(fd, &c, 1) < 1)
			return (NULL);
		ft_list_push_back(&head, c);
		i++;
	}
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	linked_to_string(head, dest);
	ft_list_clear(head);
	ft_atoa(dest);
	return (dest);
}

int	ft_parse_dict(char *nbr, int fd, t_list **head_written)
{
	char	c;
	char	*str;

	str = ft_get_dict_nbr(fd);
	if (str == NULL)
		return (1);
	if (!ft_strcmp(nbr, str))
	{
		free(str);
		if (read(fd, &c, 1) < 1)
			return (1);
		while (c == ' ' || c == ':')
			if (read(fd, &c, 1) < 1)
				return (1);
		while (c != '\n')
		{
			ft_list_push_back(head_written, c);
			if (read(fd, &c, 1) < 1)
				return (1);
		}
		return (1);
	}
	free(str);
	return (0);
}

t_list	*ft_get_written_nbr(char *nbr, char *dict_name)
{
	int		fd;
	t_list	*head_written;

	head_written = NULL;
	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (!ft_parse_dict(nbr, fd, &head_written))
		;
	if (close(fd) < 0)
		return (NULL);
	return (head_written);
}

int	parse_dict(char *str, char *dict)
{
	char	**n;
	int		i;
	t_list	**t;

	n = split_nbr(str, ft_strlen(str));
	i = -1;
	while (n[++i] != NULL)
		;
	t = (t_list **)malloc((i + 1) * sizeof(t_list *));
	if (t == NULL)
		return (1);
	i = -1;
	while (n[++i] != NULL)
	{
		t[i] = ft_get_written_nbr(n[i], dict);
		free(n[i]);
		if (t[i] == NULL)
			ft_putstr("Dict Error\n");
		if (t[i] == NULL)
			return (1);
	}
	free(n);
	t[i] = NULL;
	print_linked_array(t);
	return (0);
}
