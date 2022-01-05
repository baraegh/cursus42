/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:42:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/05 20:44:41 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_new_save(char *str_saved)
{
	int		i;
	int		j;
	char	*new_save;

	i = ft_strchr_gnl(str_saved, '\n');
	if (i == -1)
	{
		free(str_saved);
		return (0);
	}
	new_save = (char *) malloc(ft_strlen_gnl(str_saved) - i + 1);
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
	i = ft_strchr_gnl(str_saved, '\n');
	if (i == -1)
		line = (char *)malloc(ft_strlen_gnl(str_saved) + 1);
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
	while (read_bytes != 0 && ft_strchr_gnl(str_saved, '\n') == -1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_bytes] = '\0';
		str_saved = ft_strjoin_gnl(str_saved, buf);
	}
	free(buf);
	return (str_saved);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str_saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	str_saved = ft_read_save(fd, buf, str_saved);
	if (!str_saved)
		return (0);
	line = ft_get_line(str_saved);
	str_saved = ft_get_new_save(str_saved);
	return (line);
}
