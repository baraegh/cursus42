/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:18:55 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/10 22:10:08 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_result(const char *str, int i)
{
	int result;
	
	result = 0;
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

static int ft_check_over_long(const char *str)
{
	int	i;
	int	digit_len;

	i = 0;
	while (!ft_isdigit(*(str + i)))
		i++;
	digit_len = 0;
	while (ft_isdigit(*(str + i)))
	{
		i++;
		digit_len++;
	}
	return (digit_len--);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;

	i = 0;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\r'
			|| *(str + i) == '\n' || *(str + i) == '\v' 
			|| *(str + i) == '\f')
		i++;
	if (*(str + i) == '-')
	{
		sign *= -1;
		i++;
	}
	else if (*(str + i) == '+')
		i++;
	if (ft_check_over_long((str + i)) >= 20 && sign == 1)
		return (-1);
	else if (ft_check_over_long((str + i)) >= 20 && sign == -1)
		return (0);
	else
		return (sign * ft_result(str, i));
}
