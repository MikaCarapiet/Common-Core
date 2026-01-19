/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:29:29 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/25 14:52:09 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
	{
		str = (char *)malloc((1) * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((total_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, total_len + 1);
	return (str);
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