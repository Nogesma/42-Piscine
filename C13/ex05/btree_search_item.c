//
// Created by Mano Segransan on 8/23/21.
//

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
						int(*cmpf)(void*, void*))
{
	t_btree	*elem;

	if (root == NULL)
		return (NULL);
	elem = btree_search_item(root->left, data_ref, cmpf);
	if (elem)
		return (elem);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	elem = btree_search_item(root->right, data_ref, cmpf);
	return (elem);
}
