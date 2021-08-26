//
// Created by Mano Segransan on 8/23/21.
//

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*elem;

	elem = malloc(sizeof(t_btree));
	elem->item = item;
	elem->left = NULL;
	elem->right = NULL;
	return (elem);
}
