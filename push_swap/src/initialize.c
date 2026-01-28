/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:36:13 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/28 09:52:18 by mcarapie         ###   ########.fr       */
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
		printf("a %d\n", ptr->content);
		ptr = ptr->next;
	}
	push(a, b);
	push(a, b);
	push(a, b);
	ptr = *b;
	while (ptr)
	{
		printf("b %d\n", ptr->content);
		ptr = ptr->next;
	}
	return (0);
}
