/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:31:24 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:58:26 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	int		i;
	size_t	offset;
	int		space;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	offset = dstlen;
	i = 0;
	if (size <= dstlen)
	{
		return (size + srclen);
	}
	space = (size - dstlen - 1);
	while (src[i] != '\0')
	{
		dst[offset + i] = src[i];
		if (space == 0)
			break ;
		i++;
		space--;
	}
	dst[(offset + i)] = '\0';
	return (dstlen + srclen);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char dest[] = "Hello";
// 	char src[] = "World";
// 	int size = 3;

// 	int r;

// 	r = ft_strlcat(dest, src, size);

// 	printf("Value returned: %d\n", r);
// 	if (r > size)
// 		puts("String truncated");
// 	else
// 		puts("String was fully copied");
// 	printf("%s", dest);
// 	return (0);
// }
