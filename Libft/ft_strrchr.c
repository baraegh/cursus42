/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:05:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/10 18:20:03 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	if (c > 255 || !*s)
		return (0);
	len = ft_strlen(s);
	str = (char *)(s + len);
	while (len >= 0)
	{
		if (*str == c)
			return ((char *)str);
		str--;
	}
	return (0);
}