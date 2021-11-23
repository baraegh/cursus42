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

char *free_buf(char *buf, char *str_read)
{
    free(str_read);
    free(buf);
    return (0);
}

char *get_next_line(int fd)
{
    char        *buf;
    static char *str_read = NULL;
    char        *line;
    int         readed_bytes;
    int         index;

    if (fd < 0)
        return (0);
    buf = (char *) malloc(BUFFER_SIZE + 1);
    if(!buf)
        return (0);
    readed_bytes = 1;
    while (readed_bytes != 0 && ft_strchr(str_read, '\n') == -1)
    {
        readed_bytes = read(fd, buf, BUFFER_SIZE);
        if (readed_bytes == -1)
            return (free_buf(buf, str_read));
        buf[readed_bytes] = '\0';
        str_read = ft_strjoin(str_read, buf);
    }
    index = ft_strchr(str_read, '\n');
    if (index != -1 )
    {
        line = ft_substr(str_read, 0, index + 1);
        str_read = ft_strdup(str_read + index + 1);
        free(buf);
        return (line);
    }
    else if (readed_bytes == 0 && !*str_read)
        return (free_buf(buf, str_read));
    line = str_read;
    str_read = NULL;
    free(buf);
    return (line);
}

// int main()
// {
//     int fd = open("file", O_RDONLY);

//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));

//     close(fd);
//     return (0);
// }