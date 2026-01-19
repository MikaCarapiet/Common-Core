/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:25:35 by mcarapie          #+#    #+#             */
/*   Updated: 2025/12/01 13:34:05 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 4096

static char	**free_array(char **strings, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

static int	get_size(char const *s, char c)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			size++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (size);
}

static char	*fill_words(char **strings, char const *s, char c, int *len)
{
	int		k;
	char	buffer[BUFFER_SIZE];
	int		j;

	j = *len;
	while (s[j] == c)
		j++;
	k = 0;
	while (s[j] != c && s[j] != '\0')
	{
		buffer[k] = s[j];
		j++;
		k++;
	}
	buffer[k] = '\0';
	*strings = malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!*strings)
		return (NULL);
	ft_memcpy(*strings, buffer, ft_strlen(buffer) + 1);
	j++;
	*len = j;
	return (*strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = get_size(s, c);
	strings = malloc((size + 1) * sizeof(char **));
	if (!strings)
		return (NULL);
	while (i < size)
	{
		strings[i] = fill_words(&strings[i], s, c, &j);
		if (strings[i] == NULL)
		{
			free_array(strings, i);
			return (NULL);
		}
		i++;
	}
	strings[i] = NULL;
	return (strings);
}

// int	main(void)
// {
// 	char *s;
// 	char c;
// 	char **str;
// 	size_t i;

// 	s = "asdasd..asda ";
// 	c = '.';
// 	str = ft_split(s, c);
// 	i = 0;
// 	if (str == NULL)
// 		return (0);
// 	while (str[i] != NULL)
// 	{
// 		printf("[%s]", str[i]);
// 		i++;
// 	}
// 	free_array(str, i);
// 	return (0);
// }