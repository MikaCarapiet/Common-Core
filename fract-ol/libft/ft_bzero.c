/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:13:37 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 12:00:12 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <strings.h> // Header for bzero()

// int	main(void)
// {
// 	char buffer1[50];
// 	char buffer2[50];

// 	// Initialize the buffer with some non-zero values (for demonstration)
// 	for (int i = 0; i < 50; i++)
// 	{
// 		buffer1[i] = 'A' + (i % 26);
// 		buffer2[i] = 'A' + (i % 26);
// 	}
// 	printf("Buffer1 before bzero: %s\n", buffer1);

// 	// Clear the first 20 bytes of the buffer using bzero()
// 	bzero(buffer1, 20);

// 	printf("Buffer1 after bzero (first 20 bytes cleared): %s\n", buffer1);

// 	printf("Buffer2 before ft_bzero: %s\n", buffer2);

// 	// Clear the first 20 bytes of the buffer using bzero()
// 	ft_bzero(buffer2, 20);

// 	printf("Buffer2 after ft_bzero (first 20 bytes cleared): %s\n", buffer2);

// 	return (0);
// }
