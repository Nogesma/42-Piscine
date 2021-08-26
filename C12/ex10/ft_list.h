//
// Created by Mano Segransan on 8/17/21.
//

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	  struct s_list	*next;
	  void			*data;
}	t_list;

t_list	*ft_create_elem(void *data);

#endif //FT_LIST_H
