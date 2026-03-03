/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:45:27 by mcarapie          #+#    #+#             */
/*   Updated: 2026/03/03 15:59:19 by mcarapie         ###   ########.fr       */
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

	size = stack_size(*a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			int top = (*a)->content; // already indexed
			if ((top >> bit) & 1)
				rotate(a, "ra"); // bit is 1 → rotate
			else
				push(a, b, "pb"); // bit is 0 → push to B
			i++;
		}
		while (*b)
			push(a, b, "pa"); // push all back
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
