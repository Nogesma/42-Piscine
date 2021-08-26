//
// Created by Mano Segransan on 8/20/21.
//
#ifndef LIST_H
# define LIST_H

typedef struct s_t_list
{
	  char				c;
	  struct s_t_list	*next;
}	t_list;

t_list	*ft_create_elem(char c);

void	ft_create_list(int n);

int		ft_atoi(char *str);

#endif //LIST_H
