/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:09:08 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/24 16:58:48 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	m;
	int		i;

	m = 0;
	while (s[m] != '\0')
	{
		m++;
	}
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (m > 0)
	{
		ptr[i] = s[i];
		i++;
		m--;
	}
	ptr[i] = '\0';
	return (ptr);
}
// int	main(void)
// {
// 	const char *source_string = "Hello, strdup!";
// 	char *duplicate_string;

// 	// Duplicate the string
// 	duplicate_string = ft_strdup(source_string);

// 	if (duplicate_string == NULL)
// 	{
// 		perror("Memory allocation failed");
// 		return (1);
// 	}

// 	printf("Source string: %s\n", source_string);
// 	printf("Duplicate string: %s\n", duplicate_string);

// 	// Free the allocated memory
// 	free(duplicate_string);

// 	return (0);
// }