/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:52:46 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:58:02 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*safe_malloc(char **str, int len)
{
	*str = (char *)malloc((len + 1) * sizeof(char));
	if (*str == NULL)
		return (NULL);
	return (*str);
}

static int	trim_helper(char const *s1, int *i, char const *set)
{
	int	j;
	int	index;
	int	length;
	int	len_index;

	index = *i;
	len_index = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] != '\0' && index <= len_index)
	{
		while (s1[index] == set[j])
		{
			j = 0;
			index++;
		}
		while (s1[len_index] == set[j] && s1[index] != '\0')
		{
			j = 0;
			len_index--;
		}
		j++;
	}
	*i = index;
	length = len_index - index + 1;
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		len;

	if (s1 != NULL && set != NULL)
	{
		i = 0;
		len = trim_helper(s1, &i, set);
		if (safe_malloc(&str, len) == NULL)
			return (NULL);
		ft_memcpy(str, &s1[i], len);
		str[len] = '\0';
		return (str);
	}
	else if (set == NULL)
	{
		if (safe_malloc(&str, ft_strlen(s1)) == NULL)
			return (NULL);
		ft_memcpy(str, s1, ft_strlen(s1));
		str[ft_strlen(s1)] = '\0';
		return (str);
	}
	str = ft_calloc(1, sizeof(char));
	return (str);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*set;
// 	char	*result;

// 	str = "  abc  ";
// 	set = " abc";
// 	result = ft_strtrim(str, set);
// 	printf("%s", result);
// 	free(result);
// }

// // Edge Cases Handled -empty string -NULL string -empty set -NULL set
// -empty
