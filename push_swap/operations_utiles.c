/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:54:36 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/17 23:05:55 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_stack *stack)
{
    int tmp;

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
    if(stack_is_empty(stack))
        return (INT_MIN);
    return (stack->array[stack->top--]);
}