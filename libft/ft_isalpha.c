/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:54:01 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/18 11:57:44 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1024);
	}
	else
	{
		return (0);
	}
}
// #include <ctype.h>
// #include <stdio.h> // Required for printf()

// int	main(void)
// {
// 	int result = ft_isalpha('2');
// 	int def = isalpha('H');
// 	// Call add() and store its return value in 'result'
// 	printf("The sum is: %d\n", result); // Print the stored value
// 	printf("The sum is: %d\n", def);    // Print the stored value

// 	return (0);
// }