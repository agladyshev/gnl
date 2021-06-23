/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <stiffiny@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:13:18 by stiffiny          #+#    #+#             */
/*   Updated: 2021/06/23 12:27:17 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;
	size_t	i;

	i = 0;
	p = 0;
	len = ft_strlen(s);
	p = malloc(len + 1);
	if (p == 0)
		return (0);
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (dest == 0)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == 0)
		return (0);
	while (s1[j] != 0)
	{
		p[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = 0;
	return (p);
}
