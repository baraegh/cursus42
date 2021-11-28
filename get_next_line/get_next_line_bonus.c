/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:42:26 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/27 19:59:08 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_new_save(char *str_saved)
{
	int		i;
	int		j;
	char	*new_save;

	i = ft_strchr(str_saved, '\n');
	if (i == -1)
	{
		free(str_saved);
		return (0);
	}
	new_save = (char *) malloc(ft_strlen(str_saved) - i + 1);
	if (!new_save)
		return (0);
	i++;
	j = 0;
	while (*(str_saved + i))
		new_save[j++] = str_saved[i++];
	*(new_save + j) = '\0';
	free(str_saved);
	return (new_save);
}

char	*ft_get_line(char *str_saved)
{
	int		i;
	char	*line;

	if (!*str_saved)
		return (0);
	i = ft_strchr(str_saved, '\n');
	if (i == -1)
		line = (char *)malloc(ft_strlen(str_saved) + 1);
	else
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	line = ft_copy(line, str_saved);
	return (line);
}

char	*ft_read_save(int fd, char *buf, char *str_saved)
{
	int			read_bytes;

	read_bytes = 1;
	while (read_bytes != 0 && ft_strchr(str_saved, '\n') == -1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_bytes] = '\0';
		str_saved = ft_strjoin(str_saved, buf);
	}
	free(buf);
	return (str_saved);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str_saved[OPEN_MAX + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	str_saved[fd] = ft_read_save(fd, buf, str_saved[fd]);
	if (!str_saved[fd])
		return (0);
	line = ft_get_line(str_saved[fd]);
	str_saved[fd] = ft_get_new_save(str_saved[fd]);
	return (line);
}
