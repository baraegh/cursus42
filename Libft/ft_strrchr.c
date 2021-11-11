/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:05:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/11 14:15:41 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	if (c > 383 || !*s)
		return (0);
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	len = ft_strlen(s);
	str = (char *)(s + len - 1);
	while (len > 0)
	{
		if (*str == (char)c)
			return ((char *)str);
		len--;
		str--;
	}
	return (0);
}