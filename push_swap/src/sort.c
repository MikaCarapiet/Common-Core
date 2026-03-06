/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:45:27 by mcarapie          #+#    #+#             */
/*   Updated: 2026/03/03 17:48:44 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	sort(t_stack **a, t_stack **b, int size)
{
	if (is_unsorted(*a))
	{
		if (size <= 5)
			return (hardcode_sort(a, b, size));
		assign_indexes(*a);
		radix_sort(a, b);
	}
	return (0);
}

int	is_unsorted(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr->next)
	{
		if (ptr->content < ptr->next->content)
			ptr = ptr->next;
		else
			return (1);
	}
	return (0);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;
	int	top;

	size = stack_size(*a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			top = (*a)->index;
			if ((top >> bit) & 1)
				rotate(a, "ra");
			else
				push(a, b, "pb");
			i++;
		}
		while (*b)
			push(b, a, "pa");
		bit++;
	}
}

int	get_max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < n)
		bits++;
	return (bits);
}

void	assign_indexes(t_stack *a)
{
	int		rank;
	int		size;
	t_stack	*min_node;
	t_stack	*temp;

	size = stack_size(a);
	rank = 0;
	while (rank < size)
	{
		temp = a;
		min_node = NULL;
		while (temp)
		{
			if (temp->index == -1)
				if (!min_node || temp->content < min_node->content)
					min_node = temp;
			temp = temp->next;
		}
		min_node->index = rank;
		rank++;
	}
}
