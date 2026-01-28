/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:28:13 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/28 13:19:57 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;

	if (!*src)
	{
	}
	else
	{
		first = *src;
		second = (*src)->next;
		if (!(*dst))
			temp = NULL;
		else
			temp = (*dst);
		(*dst) = first;
		first->next = temp;
		*src = second;
	}
}

void	reverse_rotate(t_stack **head)
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
		last->next = first;
		penultimate->next = NULL;
		*head = last;
	}
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
