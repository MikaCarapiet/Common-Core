/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:56:14 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/28 10:57:28 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

t_stack	*ft_lstnew_stack(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_lstlast_stack(t_stack *head)
{
	t_stack	*ptr;

	if (head == NULL)
	{
		return (NULL);
	}
	ptr = head;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

t_stack	*ft_lstpen_stack(t_stack *head)
{
	t_stack	*ptr;

	if (head == NULL)
	{
		return (NULL);
	}
	ptr = head;
	while (ptr->next->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

void	insert_beginning(t_stack **root, int content)
{
	t_stack	*new_node;

	new_node = ft_lstnew_stack(content);
	new_node->next = *root;
	*root = new_node;
}

int	deallocate(t_stack **root)
{
	t_stack	*curr;
	t_stack	*aux;

	curr = *root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	long	*list;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	size = argc - 1;
	if (validate_arg(argc, argv, &list))
		return (1);
	if (initialize_stacks(&stack_a, &stack_b, list, size))
		return (1);
	return (free(list), deallocate(&stack_a));
}
