/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:29:50 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/11 16:26:57 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!d && !s)
		return (0);
	while (len -- > 0)
		*d++ = *s++;
	return (d);
}

// int main()
// {
// 	char s[] = {65, 66, 67, 68, 69, 0, 45};
// 	//char s0[] = { 0,  0,  0,  0,  0,  0, 0};

// 	printf("%s\n%s", (char*) memmove(s, s + 2, 0), (char*) ft_memmove(s, s + 2, 0));
// }