/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:00:02 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/18 13:08:13 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
	{
		c -= 32;
		return (c);
	}
	else
	{
		return (c);
	}
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char ch;

// 	ch = 120;
// 	printf("%c in uppercase is represented as  %c", ch, ft_toupper(ch));
// 	printf("%c in uppercase is represented as  %c", ch, toupper(ch));

// 	return (0);
// }