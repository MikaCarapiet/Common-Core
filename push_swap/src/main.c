/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:56:14 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/26 14:50:26 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	print_error(char *str)
{
	printf("%s", str);
	return (1);
}

Node	*ft_lstnew_node(int content)
{
	Node	*n;

	n = malloc(sizeof(Node));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}

int	ft_lstsize_node(Node *lst)
{
	int		i;
	Node	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
long	ft_strtol(const char *strg)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if ((strg[i] >= 9 && strg[i] <= 13) || (strg[i] >= 'A' && strg[i] <= 'Z')
		|| (strg[i] >= 'a' && strg[i] <= 'z') || strg[i] == ' '
		|| strg[i] == '+')
		return (LONG_MAX);
	else if (strg[i] == '-')
	{
		sign *= -1;
		i += 1;
	}
	while (strg[i] != '\0')
	{
		if (strg[i] >= '0' && strg[i] <= '9')
			res = res * 10 + (strg[i] - '0');
		else
			return (res * sign);
		i++;
	}
	return (res * sign);
}

int	validate_arg(int argc, char **argv)
{
	int		i;
	long	*list;
	int		list_size;
	int		n;

	n = 0;
	if (argc < 2)
		return (print_error(""));
	list = malloc((argc - 1) * sizeof(int));
	if (list == NULL)
		return (print_error("Error\n"));
	i = 1;
	list_size = 0;
	while (i < argc)
	{
		list[list_size] = ft_strtol(argv[i]);
		if ((list[list_size] > INT_MAX) || (list[list_size] < INT_MIN))
		{
			free(list);
			return (print_error("Error\n"));
		}
		list_size++;
		i++;
	}
	while (n < list_size)
	{
		printf("list[%d] %ld\n", n + 1, list[n]);
		n++;
	}
	printf("list size = %d\n", list_size);
	return (0);
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
	if (validate_arg(argc, argv))
		return (1);
	// ft_printf("%d %s", argc, argv[1]);
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
