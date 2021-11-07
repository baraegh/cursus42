/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:18:55 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/07 17:13:40 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_result(const char *str, int i, int result)
{
	while (*(str + i))
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
			result = result * 10 + (*(str + i) - '0');
		else
			break ;
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (*(str + i) <= 32)
		i++;
	if (*(str + i) == '-')
	{
		sign *= -1;
		i++;
	}
	return (sign * ft_result(str, i, result));
}
