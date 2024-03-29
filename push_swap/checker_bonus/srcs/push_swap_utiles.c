/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:29:11 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/22 22:06:36 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static long	ft_result(char *str, int i)
{
	long	result;

	result = 0;
	while (*(str + i))
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
			result = result * 10 + (*(str + i) - '0');
		else
			break ;
		i++;
	}
	return (result);
}

long	int	ft_atol(char *str)
{
	unsigned int	i;
	int				sign;

	if (!*str)
		return (0);
	i = 0;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\r'
		|| *(str + i) == '\n' || *(str + i) == '\v'
		|| *(str + i) == '\f')
		i++;
	if (*(str + i) == '-')
	{
		sign *= -1;
		i++;
	}
	else if (*(str + i) == '+')
		i++;
	return (sign * ft_result(str, i));
}

t_stack	*ft_create_stack(unsigned int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->capacity = capacity;
	stack->top = EMPTY;
	stack->array = malloc(stack->capacity * sizeof(int));
	if (!stack->array)
	{
		free(stack);
		return (0);
	}
	return (stack);
}

int	stack_is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

int	stack_is_empty(t_stack *stack)
{
	return (stack->top == EMPTY);
}
