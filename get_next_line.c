/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <stiffiny@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:17:07 by stiffiny          #+#    #+#             */
/*   Updated: 2021/07/05 18:03:18 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_on_exit(int status, char *buf)
{
	if (buf)
		free(buf);
	return (status);
}

char	*get_cached_line(char **cache, char **line, int *fd)
{
	char	*eol_ptr;

	eol_ptr = 0;
	if (*cache && line)
	{
		eol_ptr = ft_strchr(*cache, '\n');
		if (eol_ptr)
		{
			*eol_ptr = 0;
			*line = ft_strdup(*cache);
			eol_ptr++;
			ft_strcpy(*cache, eol_ptr);
		}
		else
		{
			*line = ft_strdup(*cache);
			free(*cache);
			*cache = 0;
		}
		if (*line == 0)
			*fd = -1;
	}
	return (eol_ptr);
}

void	split_buffer(char **line, char **eol_ptr, char **cache, char *buf)
{
	char	*swap;

	if (*eol_ptr)
	{
		**eol_ptr = 0;
		*cache = ft_strdup(++(*eol_ptr));
	}
	swap = *line;
	*line = ft_strjoin(*line, buf);
	free(swap);
}

int	get_next_line(int fd, char **line)
{
	static char	*cache;
	char		*buf;
	char		*eol_ptr;
	int			bytes_read;

	if (line != 0)
		*line = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	eol_ptr = get_cached_line(&cache, line, &fd);
	if (line == 0 || fd < 0 || BUFFER_SIZE <= 0 || !buf)
		return (free_on_exit(-1, buf));
	while (eol_ptr == 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (*line == 0 && bytes_read >= 0)
			*line = ft_strdup("");
		if (bytes_read <= 0)
			return (free_on_exit(bytes_read, buf));
		buf[bytes_read] = 0;
		eol_ptr = ft_strchr(buf, '\n');
		split_buffer(line, &eol_ptr, &cache, buf);
		if (*line == 0)
			free_on_exit(-1, buf);
	}
	return (free_on_exit((cache != 0), buf));
}
