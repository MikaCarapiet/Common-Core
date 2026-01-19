/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:06:57 by mcarapie          #+#    #+#             */
/*   Updated: 2025/11/27 22:49:48 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	to_upper_strmapi(unsigned int i, char c)
// {
// 	printf("Processing character %c at index %u\n", c, i);
// 	return (char)ft_toupper((unsigned char)c);
// }
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*result;
// 	char	(*f)(unsigned int, char);

// 	f = &to_upper_strmapi;
// 	s = "";
// 	printf("before: %s\n", s);
// 	result = ft_strmapi(s, f);
// 	printf("after: %s\n", result);
// }
