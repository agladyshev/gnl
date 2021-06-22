/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <stiffiny@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:17:07 by stiffiny          #+#    #+#             */
/*   Updated: 2021/06/21 20:42:38 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_cached_line(char **cache, char **line)
{
	char *newline;
	
	newline = 0;
	if (cache)
	{
		newline = ft_strchr(cache, '\n');
		if (newline)
		{
			newline = 0;
			*line = ft_strdup(cache);
			newline++;
			ft_strcpy(cache, newline);
		}
		else
		{
			*line = ft_strdup(cache);
			free(cache);
			cache = 0;
		}
	}
	else
		*line = ft_strdup("");
	return (newline);
}

int	get_next_line(int fd, char **line)
{
	static char	*cache;
	char	buf[BUFFER_SIZE + 1];
	char	*newline;
	char    *swap;
	int	bytes_read;

	if (line == 0 || fd < 0)
		return (-1);
    /*
	if (cache && *cache)
	{
		get_cached_line(cache, line);
	}
    */
	bytes_read = -1;
    /*
	if (!bytes_read)
		return (0);
	else
	*/
	while(bytes_read)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        buf[bytes_read] = 0;
        swap = *line;
	    *line = ft_strjoin(*line, buf);
	    free(swap);
    }
	return (0);
} 
