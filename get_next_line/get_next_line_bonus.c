/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:42:26 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/27 01:38:18 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	p = (char *) malloc(ft_strlen(s1) + 1);
	if (!p)
		return (0);
	i = 0;
	while (*s1)
	{
		*(p + i) = *s1;
		s1++;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

char	*ft_get_line(char **str_saved, int readed_bytes)
{
	char		*line;
	int			index;

	if (readed_bytes == 0 && !**str_saved)
	{
		free(*str_saved);
		*str_saved = NULL;
		return (0);
	}
	index = ft_strchr(*str_saved, '\n');
	if (index != -1)
	{
		line = ft_substr(*str_saved, 0, index + 1);
		*str_saved = ft_strdup(*str_saved + index + 1);
		return (line);
	}
	line = *str_saved;
	*str_saved = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str_saved[OPEN_MAX];
	int			readed_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	readed_bytes = 1;
	while (readed_bytes != 0 && ft_strchr(str_saved[fd], '\n') == -1)
	{
		readed_bytes = read(fd, buf, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buf);
			return (0);
		}
		buf[readed_bytes] = '\0';
		str_saved[fd] = ft_strjoin(str_saved[fd], buf);
	}
	free(buf);
	return (ft_get_line(&str_saved[fd], readed_bytes));
}
