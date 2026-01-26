/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:02:40 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:58:41 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *str, int character)
{
	unsigned char	c;

	c = character;
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	myString[] = "Hello World";
// 	char	searchChar;
// 	char	*resultPtr;

// 	searchChar = 0;
// 	resultPtr = ft_strchr(myString, searchChar);
// 	printf("%s", resultPtr);
// 	return (0);
// }
