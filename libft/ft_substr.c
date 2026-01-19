/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:37:36 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/25 14:28:25 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		size;
	char	*substr;

	size = ft_strlen(s) - start;
	if (s[0] == '\0' || size < 0)
	{
		substr = (char *)malloc((1) * sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	if ((int)len > size)
	{
		substr = (char *)malloc((size + 1) * sizeof(char));
		if (substr == NULL)
			return (NULL);
		ft_strlcpy(substr, &s[start], size + 1);
	}
	else
	{
		substr = (char *)malloc((len + 1) * sizeof(char));
		if (substr == NULL)
			return (NULL);
		ft_strlcpy(substr, &s[start], len + 1);
	}
	return (substr);
}

// int	main(void)
// {
// 	char			*s;
// 	unsigned int	start;
// 	size_t			len;
// 	char			*substr;

// 	s = "tripouille";
// 	len = 1;
// 	start = 1;
// 	substr = ft_substr(s, start, len);
// 	printf("%s", substr);
// 	free(substr);
// 	return (0);
// }
