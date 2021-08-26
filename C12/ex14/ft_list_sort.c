#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_get_middle(t_list **head)
{
	t_list	*slow;
	t_list	*fast;

	if (head == NULL)
		return (*head);
	slow = *head;
	fast = *head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

t_list	*merge(t_list *left, t_list *right, int(*cmp)())
{
	t_list	*elem;

	elem = NULL;
	if (left == NULL)
		return (right);
	if (right == NULL)
		return (left);
	if (cmp(left->data, right->data) < 0)
	{
		elem = left;
		elem->next = merge(left->next, right, cmp);
	}
	else
	{
		elem = right;
		elem->next = merge(left, right->next, cmp);
	}
	return (elem);
}

t_list	*merge_sort(t_list *head, int(*cmp)())
{
	t_list	*left;
	t_list	*middle;
	t_list	*right;

	left = head;
	if (left == NULL || left->next == NULL)
		return (head);
	middle = ft_get_middle(&head);
	right = middle->next;
	middle->next = NULL;
	return (merge(merge_sort(left, cmp), merge_sort(right, cmp), cmp));
}

void	ft_list_sort(t_list **begin_list, int(*cmp)())
{
	*begin_list = merge_sort(*begin_list, cmp);
}
