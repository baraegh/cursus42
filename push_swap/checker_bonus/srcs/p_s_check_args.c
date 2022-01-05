/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_check_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:45:49 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/04 18:22:21 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_big_int(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				if ((av[i][j] != '-' || av[i][j] != '+')
				&& !ft_isdigit(av[i][j + 1]))
					return (0);
				else if (av[i][j] != '-' && av[i][j] != '+')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_argument(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!ft_check(ac, av))
		return (0);
	if (is_big_int(ac, av))
		return (0);
	return (1);
}

int	is_has_duplicate_n(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
