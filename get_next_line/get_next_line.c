/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:42:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/20 21:49:06 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(char *s, char c)
{
    int i;

    i = 0;
    while (*(s + i))
    {
        if (*(s + i) == c)
            return (i);
        i++;
    }
    return (-1);
}

char *get_next_line(int fd)
{
    char        *buf;
    static char *str_read;
    char        *line;
    int         i;
    int         readed_bytes;
    int         index;

    if (fd < 0)
        return (0);
    buf = (char *) malloc(BUFFER_SIZE * sizeof(char));
    if(!buf)
        return (0);
    i = 0;
    readed_bytes = read(fd, buf, BUFFER_SIZE);
    if(!*buf && !*str_read)
        return (0);
    while (readed_bytes != 0)
    {
        index = ft_strchr(buf, '\n');
        if (index != -1 && readed_bytes != 0)
        {
            line = ft_strjoin(str_read, ft_substr((const char *) buf, 0, index + 1));
            str_read = ft_strdup(&buf[index + 1]);
            return (line);
        }
        str_read = ft_strjoin((const char *)str_read, (const char *)buf);
        readed_bytes = read(fd, buf, BUFFER_SIZE);
    }
    index = ft_strchr(str_read, '\n');
    if (readed_bytes == 0 && index != -1)
    {
        line = ft_substr((const char *) str_read, 0, index + 1);
        str_read = ft_strdup(&str_read[index + 1]);
        return (line);
    }
    line  = ft_strdup(str_read);
    str_read = ft_strdup("");
    return (line);
}

int main()
{
    int fd = open("file", O_RDONLY);

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));

    return (0);
}