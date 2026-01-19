/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:43:53 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/24 12:16:03 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char source_string1[] = "Hello, memcpy!";
// 	char destination_buffer1[50];
// 	printf("Source string: %s\n", source_string1);

// 	memcpy(destination_buffer1, source_string1, 0);

// 	char source_string2[] = "Hello, ft_memcpy!";
// 	char destination_buffer2[50];

// 	printf("\n");
// 	printf("Source string: %s\n", source_string2);

// 	ft_memcpy(destination_buffer2, source_string2, 0);

// 	printf("Destination buffer after ft_memcpy: %s\n", destination_buffer2);
// }