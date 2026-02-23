/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:03:51 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/11 16:14:34 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

t_stack	*ft_lstnew_stack(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_lstlast_stack(t_stack *head)
{
	t_stack	*ptr;

	if (head == NULL)
	{
		return (NULL);
	}
	ptr = head;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

t_stack	*ft_lstpen_stack(t_stack *head)
{
	t_stack	*ptr;

	if (head == NULL)
	{
		return (NULL);
	}
	ptr = head;
	while (ptr->next->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

void	insert_beginning(t_stack **root, int content)
{
	t_stack	*new_node;

	new_node = ft_lstnew_stack(content);
	new_node->next = *root;
	*root = new_node;
}

int	deallocate(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	t_stack	*aux;

	curr = *a;
	while (curr != NULL)
	{
		aux = curr->next;
		free(curr);
		curr = aux;
	}
	*a = NULL;
	curr = *b;
	while (curr != NULL)
	{
		aux = curr->next;
		free(curr);
		curr = aux;
	}
	*b = NULL;
	return (0);
}
