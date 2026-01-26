/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:03:40 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/25 11:57:50 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
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
			return (extract_line(buffer, line, leftover));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	if (fd == -1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	line = NULL;
	if (leftover != NULL)
	{
		if (ft_strchr(leftover, '\n'))
		{
			line = extract_leftover(&leftover);
			free(buffer);
			return (line);
		}
		else
		{
			line = leftover;
			leftover = NULL;
		}
	}
	line = fill_line_buffer(fd, buffer, line, &leftover);
	free(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("example.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("gnt returned : %s\n", line);
// 		free(line); // <-- Add this
// 	}
// 	close(fd);
// 	return (0);
// }
