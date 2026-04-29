/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:28:13 by mcarapie          #+#    #+#             */
/*   Updated: 2026/04/29 18:29:36 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	push(t_stack **src, t_stack **dst, char *str)
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
	ft_printf("%s\n", str);
}

void	reverse_rotate(t_stack **head, char *str)
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
	if (str)
		ft_printf("%s\n", str);
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	ft_printf("rrr\n");
}
