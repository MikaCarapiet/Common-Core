/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:04:52 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/02 10:33:16 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, nmemb * size);
	return (memory);
}
// int	main(void)
// {
// 	int *ptr = ft_calloc(2, 2);

// 	// Checking if failed or pass
// 	if (ptr == NULL)
// 	{
// 		printf("Allocation Failed");
// 		exit(0);
// 	}

// 	// No need to populate as already
// 	// initialized to 0

// 	// Print the array
// 	for (int i = 0; i < 5; i++)
// 		printf("%d ", ptr[i]);
// 	printf("\n");
// 	return (0);
// }
