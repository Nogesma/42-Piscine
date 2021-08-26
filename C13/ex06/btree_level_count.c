//
// Created by Mano Segransan on 8/23/21.
//

#include "ft_btree.h"
#include <stdlib.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	if (root == NULL)
		return (0);
	return (max(btree_level_count(root->left) + 1,
			 btree_level_count(root->right) + 1));
}
