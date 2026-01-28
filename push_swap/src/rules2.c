/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:28:13 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/28 10:56:42 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;

	insert_beginning(dst, (*src)->content);
	if (!*src)
	{
	}
	else
	{
		first = *src;
		second = *dst;
		temp = (*dst)->next;
		second->next = (*src)->next;
		first->next = temp;
		*src = second;
	}
}
