/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:46:15 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/18 15:53:48 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
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
// 	int result = ft_isascii('1');
// 	int def = isascii('1');
// 	// Call add() and store its return value in 'result'
// 	printf("The sum is: %d\n", result); // Print the stored value
// 	printf("The sum is: %d\n", def);    // Print the stored value

// 	return (0);
// }