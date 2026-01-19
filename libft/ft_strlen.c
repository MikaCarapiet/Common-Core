/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:17:04 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/02 13:04:25 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("%lu\n",
// 		ft_strlen("asgasgsdgashashahaerhaerhaerhadfhadrhadrhdrhadahdrhh"));
// 	printf("%lu\n",
// 		strlen("asgasgsdgashashahaerhaerhaerhadfhadrhadrhdrhadahdrhh"));
// }
