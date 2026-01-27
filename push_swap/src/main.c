/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:56:14 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/27 10:21:29 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

t_Node	*ft_lstnew_node(int content)
{
	t_Node	*n;

	n = malloc(sizeof(t_Node));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}

int	ft_lstsize_node(t_Node *lst)
{
	int		i;
	t_Node	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

// int	check_error(char **string_nums)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (string_nums[i] != NULL)
// 	{
// 		j = 0;
// 		ft_printf("%d - %s \n", i + 1, string_nums[i]);
// 		while (string_nums[i][j] != '\0')
// 		{
// 			if (ft_strchr("0123456789", string_nums[i][j]))
// 				j++;
// 			else
// 				return (print_error("Error\n"));
// 		}
// 		i++;
// 	}
// 	return (0);
// }
// Node	*get_stack(char *argv, int *stacklen)
// {
// 	char	**string_nums;
// 	Node	*stack_a;

// 	// int		i;
// 	// i = 0;
// 	string_nums = ft_split(argv, ' ');
// 	if (check_error(string_nums))
// 		return (NULL);
// 	stack_a = ft_lstnew_node(100);
// 	*stacklen = ft_lstsize_node(stack_a);
// 	return (stack_a);
// }

int	main(int argc, char **argv)
{
	long	*list;
	int		size;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	if (validate_arg(argc, argv, &size, &list))
		return (1);
	while (i < (size))
	{
		printf("%ld\n", list[i]);
		i++;
	}
	printf("size = %d\n", size);
	free(list);
	return (0);
}

// Node	*ft_lstnew_node(int content)
// {
// 	Node	*n;

// 	n = malloc(sizeof(Node));
// 	if (n == NULL)
// 		return (NULL);
// 	n->content = content;
// 	n->next = NULL;
// 	return (n);
// }
// Node	*ft_lstlast_node(Node *lst)
// {
// 	Node	*ptr;

// 	if (lst == NULL)
// 	{
// 		return (NULL);
// 	}
// 	ptr = lst;
// 	while (ptr->next)
// 	{
// 		ptr = ptr->next;
// 	}
// 	return (ptr);
// }
// void	insert_end(Node **root, int value)
// {
// 	Node	*new_node;
// 	Node	*ptr;

// 	new_node = ft_lstnew_node(value);
// 	if (*root == NULL)
// 	{
// 		*root = new_node;
// 		return ;
// 	}
// 	ptr = *root;
// 	ptr = ft_lstlast_node(*root);
// 	ptr->next = new_node;
// }

// void	deallocate(Node **root)
// {
// 	Node	*curr;
// 	Node	*aux;

// 	curr = *root;
// 	while (curr != NULL)
// 	{
// 		aux = curr;
// 		curr = curr->next;
// 		free(aux);
// 	}
// 	*root = NULL;
// }
