/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:15:40 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/24 15:26:06 by mcarapie         ###   ########.fr       */
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
	else if (size == 5)
		return (five_sort(a, b));
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
	if (max < mid)
		max = mid;
	else if (max < bottom)
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

	get_min_val(a, &min_pos);
	if (min_pos == 1)
		rotate(a, "ra");
	else if (min_pos == 2)
	{
		reverse_rotate(a, "rra");
		reverse_rotate(a, "rra");
	}
	else if (min_pos == 3)
		reverse_rotate(a, "rra");
	push(a, b, "pb");
	three_sort(a);
	push(b, a, "pa");
	return (0);
}

int	five_sort(t_stack **a, t_stack **b)
{
	int	min_pos;

	get_min_val(a, &min_pos);
	push_min_val(a, b, min_pos);
	get_min_val(a, &min_pos);
	push_min_val(a, b, min_pos);
	three_sort(a);
	push(b, a, "pa");
	push(b, a, "pa");
	return (0);
}
void	get_min_val(t_stack **a, int *min_pos)
{
	int		min_val;
	int		current_pos;
	t_stack	*ptr;

	min_val = (*a)->content;
	ptr = (*a);
	*min_pos = 0;
	current_pos = 0;
	while (ptr)
	{
		if (min_val > ptr->content)
		{
			min_val = ptr->content;
			*min_pos = current_pos;
		}
		current_pos = current_pos + 1;
		ptr = ptr->next;
	}
}

void	push_min_val(t_stack **a, t_stack **b, int min_pos)
{
	if (min_pos == 1)
		rotate(a, "ra");
	if (min_pos == 2)
	{
		rotate(a, "rra");
		swap(a, "sa");
	}
	if (min_pos == 3)
	{
		reverse_rotate(a, "rra");
		reverse_rotate(a, "rra");
	}
	if (min_pos == 4)
		reverse_rotate(a, "rra");
	push(a, b, "pb");
}