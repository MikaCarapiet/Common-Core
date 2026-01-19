/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:09:20 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/02 10:33:16 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		c += 32;
	return (c);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char ch;

// 	ch = 65;
// 	printf("%c in lowercase is represented as  %c", ch, ft_tolower(ch));
// 	printf("%c in lowercase is represented as  %c", ch, tolower(ch));

// 	return (0);
// }