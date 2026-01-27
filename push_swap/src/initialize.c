/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:36:13 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/28 00:43:21 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

t_stack	*initialize_stack_a(long *list, int size)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 0;
	while (size > i)
	{
		size--;
		insert_beginning(&a, (int)list[size]);
	}
	return (a);
}

t_stack	*initialize_stack_b(void)
{
	t_stack	*b;

	b = NULL;
	return (b);
}

t_stack	*swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;

	if (!*head || !(*head)->next)
		return (*head);
	first = *head;
	second = (*head)->next;
	temp = second->next;
	second->next = first;
	first->next = temp;
	*head = second;
	return (*head);
}

t_stack	*rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*penultimate;

	if (!*head || !(*head)->next)
		return (*head);
	first = *head;
	penultimate = ft_lstpen_stack(*head);
	last = ft_lstlast_stack(*head);
	last->next = (*head)->next;
	penultimate->next = first;
	first->next = NULL;
	*head = last;
	return (*head);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	*a = rotate(a);
	*b = rotate(b);
}

void	swap_both(t_stack **a, t_stack **b)
{
	*a = swap(a);
	*b = swap(b);
}

int	initialize_stacks(t_stack **a, t_stack **b, long *list, int size)
{
	t_stack	*ptr;

	*a = initialize_stack_a(list, size);
	*b = initialize_stack_b();
	if (!*a)
		return (print_error("Error\n"));
	ptr = *a;
	while (ptr)
	{
		printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
	rotate_both(a, b);
	ptr = *a;
	while (ptr)
	{
		printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
	return (0);
}
