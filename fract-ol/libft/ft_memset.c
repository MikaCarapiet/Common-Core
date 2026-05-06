/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:31:23 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:59:07 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int	main(void)
// {
// 	char buffer1[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX";
// 	char buffer2[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX";

// 	printf("Buffer1 before memset: %s\n", buffer1);

// 	// Clear the first 20 bytes of the buffer using bzero()
// 	memset(buffer1, 65, 20);

// 	printf("Buffer1 after memset (first 20 bytes cleared): %s\n", buffer1);

// 	printf("Buffer2 before memset: %s\n", buffer2);

// 	// // Clear the first 20 bytes of the buffer using bzero()
// 	ft_memset(buffer2, 65, 20);

// 	printf("Buffer2 after memset (first 20 bytes cleared): %s\n", buffer2);

// 	return (0);
// }
