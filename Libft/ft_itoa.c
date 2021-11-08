/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:12:34 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/08 11:24:26 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_count_digits(long nb)
{
	long	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static char	*ft_num_to_char(char *str, long n, long i, long size)
{
	long	j;

	j = size - 1;
	while (j >= i && n != 0)
	{
		str[j--] = (n % 10) + '0';
		n /= 10;
	}
	str[size + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	long	i;
	long	size;

	nb = n;
	size = ft_count_digits(nb);
	str = (char *) malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	if (nb == 0)
	{
		str[i] = '0';
		return (str);
	}
	if (nb < 0)
	{
		nb = -nb;
		str[i] = '-';
		i++;
	}
	return (ft_num_to_char(str, nb, i, size));
}
