/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:06:11 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 14:36:24 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
// int	main(void)
// {
// 	char *my_string;
// 	char *new_string;
// 	t_list *new_node;
// 	t_list *next_node;
// 	// Create a string to be used as content
// 	my_string = "Hello, 42!";
// 	new_string = "Hello again, 42!";
// 	// Create a new node using ft_lstnew
// 	new_node = ft_lstnew(my_string);
// 	next_node = ft_lstnew(new_string);

// 	ft_lstadd_front(&new_node->next, next_node);
// 	// Check if the allocation was successful
// 	printf("Node 1 content: %s\n", (char *)new_node->content);
// 	printf("Node 2 content: %s\n", (char *)new_node->next->content);

// 	return (0);
// }
