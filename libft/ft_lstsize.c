/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:06:43 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/02 10:56:09 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
// int	main(void)
// {
// 	char *string1;
// 	char *string2;
// 	char *string3;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	int length = 0;
// 	// Create a string to be used as content
// 	string1 = "1";
// 	string2 = "2";
// 	string3 = "3";
// 	// Create a new node using ft_lstnew
// 	node1 = ft_lstnew(string1);
// 	node2 = ft_lstnew(string2);
// 	node3 = ft_lstnew(string3);
// 	int i = 0;

// 	ft_lstadd_front(&node1->next, node2);
// 	ft_lstadd_front(&node2->next, node3);
// 	// Check if the allocation was successful
// 	length = ft_lstsize(node1);
// 	printf("list size: %d\n", length);

// 	return (0);
// }