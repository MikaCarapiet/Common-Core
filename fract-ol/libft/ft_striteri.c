/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:48:28 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:58:36 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// void	iter_tolower(unsigned int i, char *c)
// {
// 	// A simple implementation of tolower within the function
// 	if (*c >= 'A' && *c <= 'Z')
// 		*c = *c + 32;
//
// 	(void)i;
// }
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
// int	main(void)
// {
// 	char	str[] = "HeLlO wOrLd! 42 PAris";

// 	printf("Original string: %s\n", str);
// 	// Apply ft_striteri to the string using the helper function
// 	ft_striteri(str, iter_tolower);
// 	printf("Lowercase string: %s\n", str);
// 	return (0);
// }
