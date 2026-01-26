/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:30:32 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:58:22 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

// int	main(void)
// {
// 	char	source[] = "Hello, world!";
// 	size_t	copied_len1;
// 	size_t	copied_len2;
// 	char	empty_source[] = "";
// 	char	dest_for_empty[10];
// 	size_t	copied_len3;

// 	char destination[20];      // Buffer size of 20 characters
// 	char small_destination[5]; // Buffer size of 5 characters
// 	// Example 1: Successful copy
// 	copied_len1 = ft_strlcpy(destination, source, sizeof(destination));
// 	printf("Destination (full size): \"%s\" (copied length: %zu)\n",
// 		destination, copied_len1);
// 	if (copied_len1 >= sizeof(destination))
// 	{
// 		printf("Warning: String was truncated!\n");
// 	}
// 	// Example 2: Truncated copy
// 	copied_len2 = ft_strlcpy(small_destination, source,
// 			sizeof(small_destination));
// 	printf("Destination (small size): \"%s\" (copied length: %zu)\n",
// 		small_destination, copied_len2);
// 	if (copied_len2 >= sizeof(small_destination))
// 	{
// 		printf("Warning: String was truncated!\n");
// 	}
// 	// Example 3: Copying an empty string
// 	copied_len3 = ft_strlcpy(dest_for_empty, empty_source,
// 			sizeof(dest_for_empty));
// 	printf("Destination (empty source): \"%s\" (copied length: %zu)\n",
// 		dest_for_empty, copied_len3);
// 	return (0);
// }
