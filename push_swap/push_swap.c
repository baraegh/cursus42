/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/13 16:21:38 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(int *tab, int size)
{
	int	tmp;
	if (!tab)
		return ;
	if (size > 1)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;	
	}
}

// void push(int *src, int *dst, int size)
// {
// 	if (!src)
// 		return ;
// 	while ()
// 	{

// 	}
// }

void rotate()
{

}

void reverse_rotate()
{
	
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	printf("%d", ac);
	a = malloc((ac - 1) * sizeof(int));
	if (!a)
		return (0);
	b = maolloc((ac - 1) * sizeof(int));
	if (!b)
		return (0);
	
	
	return (0);
}