/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:06:40 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/02 10:46:38 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}

// int	main(void)
// {
// 	char	*my_string;
// 	t_list	*new_node;

// 	// Create a string to be used as content
// 	my_string = "Hello, 42!";
// 	// Create a new node using ft_lstnew
// 	new_node = ft_lstnew(my_string);
// 	// Check if the allocation was successful
// 	if (new_node)
// 	{
// 		printf("Node content: %s\n", (char *)new_node->content);
// 	}
// 	return (0);
// }
