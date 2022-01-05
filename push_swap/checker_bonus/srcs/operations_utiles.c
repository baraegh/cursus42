/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:54:36 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/05 23:17:39 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack_is_empty(stack))
		return ;
	tmp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = tmp;
}

void	push(t_stack *stack, int n)
{
	if (stack_is_full(stack))
		return ;
	stack->array[++stack->top] = n;
}

int	pop(t_stack *stack)
{
	if (stack_is_empty(stack))
		return (INT_MIN);
	return (stack->array[stack->top--]);
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack_is_empty(stack))
		return ;
	i = stack->top;
	tmp = stack->array[stack->top];
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = tmp;
}

void	rotate_reverse(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack_is_empty(stack))
		return ;
	i = 0;
	tmp = stack->array[0];
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = tmp;
}
