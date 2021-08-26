//
// Created by Mano Segransan on 8/23/21.
//

#include "ft_btree.h"
#include <stdlib.h>

void	btree_apply_suffix(t_btree *root, void(*applyf)(void*))
{
	if (root == NULL)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
