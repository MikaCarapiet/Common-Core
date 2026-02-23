/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:28:13 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/23 15:28:49 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	swap(t_stack **head, char *str)
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
	ft_printf("%s\n", str);
}

void	rotate(t_stack **head, char *str)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second;

	if (!*head || !(*head)->next)
	{
	}
	else
	{
		first = *head;
		second = (*head)->next;
		last = ft_lstlast_stack(*head);
		last->next = first;
		first->next = NULL;
		*head = second;
	}
	ft_printf("%s\n", str);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	ft_printf("rr\n");
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a, NULL);
	swap(b, NULL);
	ft_printf("ss\n");
}
