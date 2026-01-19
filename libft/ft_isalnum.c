/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:51:41 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/18 11:58:14 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) || (c >= '0'
			&& c <= '9'))
	{
		return (8);
	}
	else
	{
		return (0);
	}
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int result = ft_isalnum(0x80);
// 	int def = isalnum(0x80);
// 	printf("The sum is: %d\n", result); // Print the stored value
// 	printf("The sum is: %d\n", def);    // Print the stored value

// 	return (0);
// }