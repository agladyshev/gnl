/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <stiffiny@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:17:07 by stiffiny          #+#    #+#             */
/*   Updated: 2021/06/23 12:26:41 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_cached_line(char **cache, char **line)
{
	char	*newline;

	newline = 0;
	if (*cache)
	{
		//printf("|%s|\n", *cache);
		newline = ft_strchr(*cache, '\n');
		if (newline)
		{
			//printf("{%s}\n", newline);
			*newline = 0;
			*line = ft_strdup(*cache);
			newline++;
			ft_strcpy(*cache, newline);
		}
		else
		{
			*line = ft_strdup(*cache);
			free(*cache);
			*cache = 0;
		}
	}
	else
		*line = ft_strdup("");
	return (newline);
}

int	get_next_line(int fd, char **line)
{
	static char	*cache;
	char		*buf;
	char		*newline;
	char		*swap;
	int			bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == 0 || fd < 0 || BUFFER_SIZE == 0)
		return (-1);
	newline = get_cached_line(&cache, line);
	//printf("{%s}\n", *line);
	while (newline == 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read)
			break ;
		buf[bytes_read] = 0;
		newline = ft_strchr(buf, '\n');
		if (newline)
		{
			*newline = 0;
			newline++;
			cache = ft_strdup(newline);
		}
		swap = *line;
		*line = ft_strjoin(*line, buf);
		free(swap);
	}
	free(buf);
	if (bytes_read || **line || cache)
		return (1);
	return (0);
}
