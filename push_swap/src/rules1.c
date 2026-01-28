/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:28:13 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/28 09:49:37 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;

	if (!*head || !(*head)->next)
	{
	}
	else
	{
		first = *head;
		second = (*head)->next;
		temp = second->next;
		second->next = first;
		first->next = temp;
		*head = second;
	}
}

void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*penultimate;

	if (!*head || !(*head)->next)
	{
	}
	else
	{
		first = *head;
		penultimate = ft_lstpen_stack(*head);
		last = ft_lstlast_stack(*head);
		last->next = (*head)->next;
		penultimate->next = first;
		first->next = NULL;
		*head = last;
	}
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
