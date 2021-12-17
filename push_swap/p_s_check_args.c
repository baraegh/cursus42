/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_check_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:45:49 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/17 23:13:09 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int is_big_int(int size, char **av)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_argument(int size, char **av)
{
	int	i;
	int	j;

	if (size < 2)
		return (0);
	i = 1;
	while (i < size)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{	
				if(av[i][j] != '-' && av[i][j]!= '+')
					return (0);
			}
			j++;
		}
		i++;
	}
	if (is_big_int(size, av))
		return (0);
	return (1);
}

int	is_has_duplicate_n(t_stack *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->array[i] == stack->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
