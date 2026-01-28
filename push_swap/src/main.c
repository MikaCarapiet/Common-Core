/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:56:14 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/28 16:05:21 by mcarapie         ###   ########.fr       */
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
	return (free(list), deallocate(&stack_a) + deallocate(&stack_b));
}
