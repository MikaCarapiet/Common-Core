/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:09:06 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:58:10 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && (i + j < len) && big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	const char *largestring = "aaabcabcd";
// 	const char *smallstring = "cd";
// 	char *ptr1;
// 	char *ptr2;

// 	ptr1 = ft_strnstr(largestring, smallstring, 8);
// 	ptr2 = strnstr(largestring, smallstring, 8);
// 	printf("ft_strnstr: %s\n", ptr1);
// 	printf("strnstr: %s", ptr2);
// }
