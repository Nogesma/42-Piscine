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

void	btree_apply_current_level(t_btree *root,
	   int level, t_args *a, void(*applyf)(void *item,
		int current_level, int is_first_elem))
{
	if (root == NULL)
		return ;
	if (a->to_reach == level)
	{
		if (a->list_levels[level])
			applyf(root->item, level, 0);
		else
		{
			a->list_levels[level] = 1;
			applyf(root->item, level, 1);
		}
	}
	else
	{
		level++;
		if (root->left != NULL)
		{
			btree_apply_current_level(root->left, level, a, applyf);
			btree_apply_current_level(root->right, level, a, applyf);
		}
		else
			btree_apply_current_level(root->right, level, a, applyf);
	}
}

void	btree_apply_by_level(t_btree *root, void(*applyf)(void *item,
	int current_level, int is_first_elem))
{
	int		size;
	int		i;
	t_args	*a;

	size = btree_level_count(root);
	i = -1;
	a = (t_args *)malloc(sizeof(t_args));
	a->list_levels = (int *)malloc((size + 1) * sizeof(int));
	while (++i <= size)
		a->list_levels[i] = 0;
	i = -1;
	while (++i < size)
	{
		a->to_reach = i;
		btree_apply_current_level(root, 0, a, applyf);
	}
	free(a->list_levels);
	free(a);
}
