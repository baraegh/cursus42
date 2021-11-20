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

char *get_next_line(int fd)
{
    char        *buf;
    char        *line;
    static char *str;
    int         i;

    if (fd <= 0)
        return (0);
    buf = (char *) malloc(BUFFER_SIZE * sizeof(char));
    if(!buf)
        return (0);
    read(fd, buf, BUFFER_SIZE);
    i = 0;
    while (*(buf + i))
    {
        if (*(buf + i) == '\0' || *(buf + i) == '\n')
            break ;
        i++;
    }
    // if (buf[i] == '\n' && buf[i] == '\0')
    // {
        line = ft_strjoin(str, ft_substr((const char *) buf, 0, i + 1));
        str = ft_substr((const char *) buf, i + 1, ft_strlen(buf));
    // }
    // else
    // {
    //     line = 0;
    //     str = ft_substr((const char *) buf, 0, i + 1);
    // }
    return(line);
}

int main()
{
    int fd = open("file", O_RDONLY);
    char    *s;
    s = (char *) malloc(sizeof(char));
    int i = 0;
    
    while (i < 10)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
    return (0);
}