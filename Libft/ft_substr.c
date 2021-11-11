/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:21:47 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/11 17:27:50 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;

	tab = (char *) malloc((len + 1) * sizeof(char));
	if (!tab || start >= ft_strlen(s))
		return (0);
	i = 0;
	while (len-- > 0)
	{
		*(tab + i) = (char)s[start];
		start++;
		i++;
	}
	*(tab + i) = '\0';
	return (tab);
}