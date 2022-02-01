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

void	push_small_num(t_stack **a, t_stack **b, int pos)
{
	int	len;

	len = (*a)->top + 1;
	if (pos == len - 1)
	{
		push(*b, pop(*a));
		ft_putstr_fd("pb\n", 1);
	} 
	else if (pos > len / 2)
	{
		pos = len - pos;
		while (pos-- > 0)
		{
			rotate_reverse(*a);
			ft_putstr_fd("rra\n", 1);
		}
	}
	else if (pos <= len / 2)
	{
		while (pos-- > 0)
		{
			rotate(*a);
			ft_putstr_fd("ra\n", 1);
		}
	}
}

void	sort_five(t_stack *a, t_stack *b, int *arr)
{
	int	i;
	int	position;

	i = a->capacity - 1;
	while (i >= 0)
		push(a, arr[i--]);
	i = 0;
	while (i < a->capacity - 3)
	{
		position = get_min_pos(a);
		push_small_num(&a, &b, position);
		i++;
	}
	sort_three(a);
	push(a, pop(b));
	push(a, pop(b));
	ft_putstr_fd("pa\npa\n", 1);
}