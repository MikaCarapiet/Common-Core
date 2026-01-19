/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:03:40 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/17 22:50:05 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// BUFFER_SIZE will be defined at compilation with -D flag
// Example: cc -D BUFFER_SIZE=42 main.c
// If not defined, this gives a default
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*extract_line(char *buffer, char *line, char **leftover)
{
	char	*newline_pos;
	char	*temp;
	char	*buffer_line;
	size_t	line_len;

	newline_pos = ft_strchr(buffer, '\n');
	line_len = newline_pos - buffer + 1;
	buffer_line = ft_substr(buffer, 0, line_len);
	if (line == NULL)
		line = buffer_line;
	else
	{
		temp = line;
		line = ft_strjoin(line, buffer_line);
		free(temp);
		free(buffer_line);
	}
	if (newline_pos[1] != '\0')
		*leftover = ft_strdup(newline_pos + 1);
	return (line);
}
char	*extract_leftover(char **leftover)
{
	size_t	line_len;
	char	*newline_pos;
	char	*line;
	char	*temp;

	newline_pos = ft_strchr(*leftover, '\n');
	line_len = newline_pos - *leftover + 1;
	line = ft_substr(*leftover, 0, line_len);
	if (newline_pos[1] != '\0')
	{
		temp = *leftover;
		*leftover = ft_strdup(newline_pos + 1);
		free(temp);
	}
	else
	{
		free(*leftover);
		*leftover = NULL;
	}
	return (line);
}
char	*fill_line_buffer(int fd, char *buffer, char *line, char **leftover)
{
	ssize_t	bytes_read;
	char	*temp;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!ft_strchr(buffer, '\n'))
		{
			if (line == NULL)
				line = ft_strdup(buffer);
			else
			{
				temp = line;
				line = ft_strjoin(line, buffer);
				free(temp);
			}
		}
		else
		{
			line = extract_line(buffer, line, leftover);
			return (line);
		}
	}
	return (line);
}
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*leftover;
	char		*line;

	if (fd == -1)
		return (NULL);
	line = NULL;
	if (leftover != NULL)
	{
		if (ft_strchr(leftover, '\n'))
		{
			line = extract_leftover(&leftover);
			return (line);
		}
		else
		{
			line = leftover;
			leftover = NULL;
		}
	}
	line = fill_line_buffer(fd, buffer, line, &leftover);
	return (line);
}

// int	main(void)
// {
// 	char	buffer[BUFFER_SIZE];
// 	ssize_t	bytes_read;
// 	int		fd;
// 	char	*line;

// 	fd = open("example.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("gnt returned : %s,%d", line, fd);
// 	close(fd);
// 	return (0);
// }
