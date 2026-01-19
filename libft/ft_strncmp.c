/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:36:38 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/24 14:28:47 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && (*s1 == *s2))
	{
		if (*s1 == '\0' || *s2 == '\0')
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "1234";
// 	char	str2[] = "1235";
// 	int		ogresult;
// 	int		ftresult;

// 	ogresult = strncmp(str1, str2, 3);
// 	ftresult = ft_strncmp(str1, str2, 3);
// 	printf("OG: %d\n", ogresult);
// 	printf("FT: %d\n", ftresult);
// 	return (0);
// }
