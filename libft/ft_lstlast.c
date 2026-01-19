/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:06:35 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/02 10:56:05 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (lst == NULL)
	{
		return (NULL);
	}
	ptr = lst;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

// int	main(void)
// {
// 	char	*string1;
// 	char	*string2;
// 	char	*string3;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;

// 	// Create a string to be used as content
// 	string1 = "1";
// 	string2 = "2";
// 	string3 = "Hello!";
// 	// Create a new node using ft_lstnew
// 	node1 = ft_lstnew(string1);
// 	node2 = ft_lstnew(string2);
// 	node3 = ft_lstnew(string3);
// 	ft_lstadd_front(&node1->next, node2);
// 	ft_lstadd_front(&node2->next, node3);
// 	printf("last list content: %s\n", (char *)ft_lstlast(node1)->content);
// 	return (0);
// }
