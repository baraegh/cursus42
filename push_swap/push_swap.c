/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/14 21:48:13 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void swap(int *tab, int size)
// {
// 	int	tmp;
// 	if (!tab)
// 		return ;
// 	if (size > 1)
// 	{
// 		tmp = tab[0];
// 		tab[0] = tab[1];
// 		tab[1] = tmp;	
// 	}
// }

// void push(int *src, int *dst, int size)
// {
// 	if (!src)
// 		return ;
// 	while ()
// 	{

// 	}
// }

// void rotate()
// {

// }

// void reverse_rotate()
// {
	
// }

int	is_valid_argument(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
		return (0);
	i = 1;
	while (i < ac)
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
	i = 1;
	while (i < ac)
	{
		if ( || ft_atoi(av[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	is_has_duplicate_n(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	i;
	int	j;

	if (!is_valid_argument(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	a = malloc((ac - 1) * sizeof(int));
	if (!a)
		return (0);
	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		a[i] = ft_atoi(av[j++]);
		i++;
	}
	if(is_has_duplicate_n(a, ac - 1))
	{
		ft_putstr_fd("Error\n", 2);
		free(a);
		exit(0);
	}
	i = 0;
	while (i < ac - 1)
	{
		printf("%d\n",a[i]);
		i++;
	}
	b = malloc((ac - 1) * sizeof(int));
	if (!b)
	{
		free(a);
		return (0);
	}
	printf("yup");
	
	return (0);
}