/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:05:43 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/02 13:04:51 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (ptr == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
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

// 	ft_lstadd_back(&new_node->next, next_node);
// 	// Check if the allocation was successful
// 	printf("Node 1 content: %s\n", (char *)new_node->content);
// 	printf("Node 2 content: %s\n", (char *)new_node->next->content);

// 	return (0);
// }