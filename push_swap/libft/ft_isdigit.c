/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:12 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/18 11:45:44 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (2048);
	}
	else
	{
		return (0);
	}
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int result = ft_isdigit('1');
// 	int def = isdigit('2');
// 	// Call add() and store its return value in 'result'
// 	printf("The sum is: %d\n", result); // Print the stored value
// 	printf("The sum is: %d\n", def);    // Print the stored value

// 	return (0);
// }