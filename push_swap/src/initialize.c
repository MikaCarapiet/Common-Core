/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:36:13 by mcarapie          #+#    #+#             */
/*   Updated: 2026/04/29 18:26:09 by mcarapie         ###   ########.fr       */
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

void	print_stack(char *str, t_stack *head)
{
	t_stack	*ptr;

	ptr = head;
	ft_printf("%s", str);
	while (ptr)
	{
		ft_printf("%d content\n", ptr->content);
		ft_printf("%dindex \n", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");
}

int	initialize_stacks(t_stack **a, t_stack **b, long *list, int size)
{
	*a = initialize_stack_a(list, size);
	*b = initialize_stack_b();
	if (!*a)
		return (print_error());
	return (0);
}
