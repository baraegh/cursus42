/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:42:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/27 03:21:56 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// char	*ft_get_new_save(char **str_saved, int index)
// {
// 	char	*new_save;
// 	int		i;

// 	new_save = (char *) malloc(ft_strlen(*str_saved + index + 1));
// 	if (!new_save)
// 		return (0);
// 	i = 0;
// 	index++;
// 	while (str_saved[0][index])
// 	{
// 		new_save[i] = str_saved[0][index];
// 		i++;
// 		index++;
// 	}
// 	new_save[i] = '\0';
// 	free(str_saved);
// 	return (new_save);
// }

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

// char	*ft_get_line(char **str_saved, int readed_bytes)
// {
// 	char		*line;
// 	int			index;

// 	if (readed_bytes == 0 && !**str_saved)
// 	{
// 		free(*str_saved);
// 		*str_saved = NULL;
// 		return (0);
// 	}
// 	index = ft_strchr(*str_saved, '\n');
// 	if (index != -1)
// 	{
// 		line = ft_substr(*str_saved, 0, index + 1);
// 		*str_saved = ft_save(*str_saved);//ft_strdup(*str_saved + index + 1);
// 		return (line);
// 	}
// 	line = *str_saved;
// 	*str_saved = NULL;
// 	return (line);
// }

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str_saved;
	int			read_bytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
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
	line = ft_get_line(str_saved);
	str_saved = ft_save(str_saved);
	return (line);
	// return (ft_get_line(&str_saved, read_bytes));
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("file", O_RDWR);

	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}