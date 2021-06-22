/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <stiffiny@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:47:23 by stiffiny          #+#    #+#             */
/*   Updated: 2021/06/21 20:09:50 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	line = ft_strdup("");
	fd = open("test.txt", O_RDONLY);
    /*
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
    */
    get_next_line(fd, &line);
    printf("%s\n", line);
	return (0);
}
