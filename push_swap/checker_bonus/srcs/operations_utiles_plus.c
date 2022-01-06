/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utiles_plus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:53:25 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/06 17:29:20 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(char *s, t_stack *stack_a, t_stack *stack_b)
{
	free(s);
	free(stack_a);
	free(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_is_equal(char *s1, char *s2)
{	
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*s2)
	{
		if (*s2 != *s1)
			return (0);
		s2++;
		s1++;
	}
	return (1);
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate_a_b(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rotate_reverse_a_b(t_stack *stack_a, t_stack *stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
}
