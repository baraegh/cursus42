/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:08:48 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/31 20:10:46 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_max(int	*arr, int size)
{
	int	i;
	int	max;

	i = 0;
	max = arr[i];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	sort_three(t_stack *stack_a)
{
	int	max;

	max = get_max(stack_a->array, stack_a->capacity);
	if (stack_a->array[0] == max)
	{
		swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (stack_a->array[1] == max)
	{
		if (stack_a->array[0] < stack_a->array[2])
		{
			rotate_reverse(stack_a);
			ft_putstr_fd("rra\n", 1);
		}
		else
		{
			swap(stack_a);
			ft_putstr_fd("sa\n", 1);
			rotate(stack_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	else if (stack_a->array[2] == max)
	{
		if (stack_a->array[1] > stack_a->array[0])
		{
			swap(stack_a);
			ft_putstr_fd("sa\n", 1);
			rotate_reverse(stack_a);
			ft_putstr_fd("rra\n", 1);
		}
		else
		{
			rotate_reverse(stack_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
}

void	sort_five(t_stack *a, t_stack *b, int *arr)
{
	int	i;

	i = a->capacity - 1;
	while (i >= 0)
		push(a, arr[i--]);
	push(b, pop(a));
	push(b, pop(a));
	ft_putstr_fd("pb\npb\n", 1);
	sort_three(a);
	push(a, pop(b));
	ft_putstr_fd("pa\n", 1);
	if (a->array[a->top] > a->array[a->top - 1])
	{
		swap(a);
		ft_putstr_fd("sa\n", 1);
	}
	if ()
	{

	}
}