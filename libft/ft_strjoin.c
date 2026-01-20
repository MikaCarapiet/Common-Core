/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:29:29 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/19 15:17:48 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(len + (1 * sizeof(char)));
	if (!s)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		s[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i])
	{
		s[len + i] = s2[i];
		i++;
	}
	s[len + i] = '\0';
	return (s);
}

// int	main(void)
// {
// 	char *s1 = "Hello";
// 	char *s2 = " World";
// 	char *s3;

// 	s3 = ft_strjoin(s1, s2);
// 	printf("%s", s3);
// 	free(s3);
// 	return (0);
// }