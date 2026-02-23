/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:15:40 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/23 18:04:03 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	hardcode_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 1)
		return (0);
	else if (size == 2)
		return (two_sort(a));
	else if (size == 3)
		return (three_sort(a));
	else if (size == 4)
		return (four_sort(a, b));
	return (1);
}

int	two_sort(t_stack **a)
{
	rotate(a, "ra");
	return (0);
}

int	three_sort(t_stack **a)
{
	int	top;
	int	mid;
	int	bottom;
	int	max;

	top = (*a)->content;
	mid = (*a)->next->content;
	bottom = ft_lstlast_stack(*a)->content;
	max = top;
	if (top < mid)
		max = mid;
	if (mid < bottom)
		max = bottom;
	if (max == top)
		rotate(a, "ra");
	else if (max == mid)
		reverse_rotate(a, "rra");
	if ((*a)->next->content < (*a)->content)
		swap(a, "sa");
	return (0);
}

int	four_sort(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	current_pos;

	get_min_val(a, &min_pos, &current_pos);
	if (min_pos == 0)
	{
		push(a, b, "pb");
		three_sort(a);
		push(b, a, "pa");
	}
	return (0);
}
void	get_min_val(t_stack **a, int *min_pos, int *current_pos)
{
	int		min_val;
	t_stack	*ptr;

	min_val = (*a)->content;
	ptr = (*a);
	*min_pos = 0;
	*current_pos = 0;
	while (ptr)
	{
		if (min_val > ptr->content)
		{
			min_val = ptr->content;
			*min_pos = *current_pos;
		}
		*current_pos = *current_pos + 1;
		ptr = ptr->next;
	}
	printf("%d = min_val, %d = min_pos\n", min_val, *min_pos);
}
