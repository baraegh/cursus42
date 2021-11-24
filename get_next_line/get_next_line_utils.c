/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:42:55 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/20 20:27:14 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (*src)
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*p;

	p = (char *) malloc(ft_strlen(s1) + 1);
	if (!p)
		return (0);
	ft_strcpy(p, s1);
	return (p);
}


static char	*ft_sub(char *tab, char *s, unsigned int start, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		*(tab + i) = (char)s[start];
		start++;
		i++;
	}
	*(tab + i) = '\0';
	free(s);
	return (tab);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*tab;
	size_t			size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > size || len == 0)
		return (ft_strdup(""));
	if (start + len < size)
	{
		tab = (char *) malloc((len + 1) * sizeof(char));
		size = len;
	}
	else
	{
		tab = (char *) malloc((size - start + 1) * sizeof(char));
		size -= start;
	}
	if (!tab)
		return (0);
	return (ft_sub(tab, s, start, size));
}

static char	*ft_strcat(char *dest, char *src)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (0);
	*str = '\0';
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return (str);
}