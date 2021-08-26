#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

typedef struct s_args
{
	int	to_reach;
	int	*list_levels;
}	t_args;

t_btree	*btree_create_node(void *item);

#endif //FT_BTREE_H
