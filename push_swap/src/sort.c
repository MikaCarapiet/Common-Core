/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:45:27 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/26 12:19:06 by mcarapie         ###   ########.fr       */
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
		else
			return (radix_sort(a, b));
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
