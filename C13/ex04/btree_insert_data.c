//
// Created by Mano Segransan on 8/23/21.
//

#include "ft_btree.h"
#include <stdlib.h>

void	btree_insert_data_rec(t_btree *root, void *item,
						   int(*cmpf)(void*, void*))
{
	if (cmpf(root->item, item) > 0)
	{
		if (root->left != NULL)
			btree_insert_data_rec(root->left, item, cmpf);
		else
			root->left = btree_create_node(item);
	}
	else
	{
		if (root->right != NULL)
			btree_insert_data_rec(root->right, item, cmpf);
		else
			root->right = btree_create_node(item);
	}
}

void	btree_insert_data(t_btree **root, void *item, int(*cmpf)(void*, void*))
{
	t_btree	*elem;

	elem = *root;
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(elem->item, item) > 0)
	{
		if (elem->left != NULL)
			btree_insert_data_rec(elem->left, item, cmpf);
		else
			elem->left = btree_create_node(item);
	}
	else
	{
		if (elem->right != NULL)
			btree_insert_data_rec(elem->right, item, cmpf);
		else
			elem->right = btree_create_node(item);
	}
}
