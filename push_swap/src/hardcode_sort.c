/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:15:40 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/23 16:00:44 by mcarapie         ###   ########.fr       */
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
	int	first;
	int	second;
	int	third;
	int	fourth;
	int	max;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	fourth = ft_lstlast_stack(*a)->content;
	max = first;
	if (first < second)
		max = second;
	if (second < third)
		max = third;
	if (third < fourth)
		max = fourth;
	if (max == first)
	{
		push(a, b, "pb");
		three_sort(a);
		push(b, a, "pa");
	}
	else if (max == second)
		reverse_rotate(a, "rra");
	if ((*a)->next->content < (*a)->content)
		swap(a, "sa");
	return (0);
}
