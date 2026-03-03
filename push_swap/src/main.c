/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:56:14 by mcarapie          #+#    #+#             */
/*   Updated: 2026/03/03 15:59:30 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

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
	free(list);
	if (sort(&stack_a, &stack_b, size))
	{
		deallocate(&stack_a, &stack_b);
		return (1);
	}
	deallocate(&stack_a, &stack_b);
	return (0);
}
