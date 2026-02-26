/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:28:17 by mcarapie          #+#    #+#             */
/*   Updated: 2026/02/26 11:14:35 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

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
	int	size;

	size = stack_size(*a);
	if (min_pos == 1)
		swap(a, "sa");
	else if (min_pos == 2)
	{
		rotate(a, "ra");
		swap(a, "sa");
	}
	else if (min_pos == 4 || (min_pos == 3 && size == 4))
		reverse_rotate(a, "rra");
	else if (min_pos == 3)
	{
		reverse_rotate(a, "rra");
		reverse_rotate(a, "rra");
	}
	push(a, b, "pb");
}

int	stack_size(t_stack *lst)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
