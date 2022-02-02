/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:59:08 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/22 22:09:21 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_intcpy(int *dst, int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int num_bit)
{
	int	i;

	i = 0;
	while (i < stack_a->capacity)
	{
		if (((stack_a->array[stack_a->top] >> num_bit) & 1) == 1)
		{
			rotate(stack_a);
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			push(stack_b, pop(stack_a));
			ft_putstr_fd("pb\n", 1);
		}
		i++;
	}
	while (!stack_is_empty(stack_b))
	{
		push(stack_a, pop(stack_b));
		ft_putstr_fd("pa\n", 1);
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	max_bits;
	int	i;

	max_bits = 0;
	max = stack_a->top;
	while ((max >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		ft_sort(stack_a, stack_b, i);
		i++;
	}
}
