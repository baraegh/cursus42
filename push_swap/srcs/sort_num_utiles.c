/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num_utiles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:02:26 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/02/02 20:04:38 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_min_pos(t_stack *a)
{
	int	i;
	int	min_i;
	int	len;

	i = 0;
	len = a->top + 1;
	min_i = i;
	while (i < len)
	{
		if (a->array[i] < a->array[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

void	push_small_num(t_stack **a, t_stack **b, int pos)
{
	int	len;

	len = (*a)->top + 1;
	if (pos < len / 2)
	{
		while (pos-- >= 0)
		{
			rotate_reverse(*a);
			ft_putstr_fd("rra\n", 1);
		}
	}
	else if (pos >= len / 2)
	{
		pos = len - 1 - pos;
		while (pos-- > 0)
		{
			rotate(*a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	push(*b, pop(*a));
	ft_putstr_fd("pb\n", 1);
}

void	ft_n1_sup_n2(t_stack *a, int n2, int n3)
{
	if (n2 > n3)
	{
		swap(a);
		rotate_reverse(a);
		ft_putstr_fd("sa\nrra\n", 1);
	}
	else if (n2 < n3)
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
	}
}

void	ft_n1_inf_n2(t_stack *a, int n1, int n3)
{
	if (n1 < n3)
	{
		swap(a);
		rotate(a);
		ft_putstr_fd("sa\nra\n", 1);
	}
	else if (n1 > n3)
	{
		rotate_reverse(a);
		ft_putstr_fd("rra\n", 1);
	}
}
