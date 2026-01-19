/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:34:00 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/24 12:33:36 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (16384);
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
// 	int result = ft_isprint(32);
// 	int def = isprint(32);
// 	printf("The sum is: %d\n", result); // Print the stored value
// 	printf("The sum is: %d\n", def);    // Print the stored value

// 	return (0);
// }