/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:06:43 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/24 14:20:36 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	character;

	i = 0;
	character = c;
	while (*s)
	{
		s++;
		i++;
	}
	while (i >= 0)
	{
		if (*s == character)
		{
			return ((char *)s);
		}
		i--;
		s--;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char *name;
// 	char *basename;
// 	name = "asd";
// 	basename = strrchr(name, '\0');
// 	printf("%s", basename);
// }