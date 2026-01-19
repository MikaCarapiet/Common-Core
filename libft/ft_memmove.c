/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:36:45 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/02 10:33:16 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	temp[100];

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = temp[i];
		i++;
	}
	return (d);
}

// int	main(void)
// {
// 	char data[] = "ABCDEFGHIJ";
// 	printf("Original: %s\n", data);

// 	// Overlapping copy using memmove (correct)
// 	// Copy "FGHIJ" (5 bytes) starting from index 5 to index 3
// 	ft_memmove(data, data + 5, 131);
// 	printf("After memmove: %s\n", data); // Expected: ABCFGHIIJ
// 	return (0);
// }