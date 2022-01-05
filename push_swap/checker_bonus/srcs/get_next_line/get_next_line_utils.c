/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:42:55 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/04 02:26:55 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl( char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (*(dest + i))
		i++;
	while (*src)
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (0);
	*str = '\0';
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return (str);
}

int	ft_strchr_gnl(char *s, char c)
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

char	*ft_copy(char *line, char *str_saved)
{
	int		i;

	i = 0;
	while (*(str_saved + i) && *(str_saved + i) != '\n')
	{
		*(line + i) = *(str_saved + i);
		i++;
	}
	if (*(str_saved + i) == '\n')
	{
		*(line + i) = *(str_saved + i);
		i++;
	}
	line[i] = '\0';
	return (line);
}
