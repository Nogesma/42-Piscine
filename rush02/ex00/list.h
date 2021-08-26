#ifndef LIST_H
# define LIST_H

typedef struct s_t_list
{
	  char				c;
	  struct s_t_list	*next;
}	t_list;

t_list	*ft_create_elem(char c);

void	ft_list_push_back(t_list **begin_list, char c);

void	ft_print_list(t_list *begin_list);

void	ft_list_clear(t_list *begin_list);

void	print_linked_array(t_list	**t);

#endif //LIST_H
