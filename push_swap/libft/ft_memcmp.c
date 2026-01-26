/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:55:39 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:59:15 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] == str2[i])
		{
			i++;
		}
		else
		{
			return (str1[i] - str2[i]);
		}
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	arr1[] = {'a', 'b', 'c', 'd', 'e'};
// 	char	arr2[] = {'a', 'b', 'c', 'x', 'y'};
// 	char	arr3[] = {'a', 'b', 'c', 'd', 'e'};
// 	char	str1[] = "Hello World";
// 	char	str2[] = "Hello w";
// 	int		result1;
// 	int		result2;
// 	int		result3;
// 	int		result4;
// 	int		result5;

// 	result1 = memcmp(arr1, arr2, -2);
// 	// Compare first 3 bytes
// 	result2 = memcmp(arr1, arr3, -5);
// 	// Compare first 5 bytes
// 	result3 = ft_memcmp(arr1, arr3, -5);
// 	result4 = memcmp(str1, str2, -5);
// 	result5 = ft_memcmp(str1, str2, -5);
// 	// Compare identical blocks
// 	printf("Result 1 (arr1 vs arr2, 3 bytes): %d\n", result1); // Should be 0
// 	printf("Result 2 (arr1 vs arr2, 5 bytes): %d\n", result2);
// 	// Should be negative
// 	printf("Result 3 (arr1 vs arr3, 5 bytes): %d\n", result3); // Should be 0
// 	printf("Result 4): %d\n", result4);                        // Should be 0
// 	printf("Result 5): %d\n", result5);                        // Should be 0
// 	return (0);
// }
