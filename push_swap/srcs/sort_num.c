/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:45:07 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/02/02 20:03:51 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_two(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sort_three(t_stack *stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	n3 = stack_a->array[0];
	n2 = stack_a->array[1];
	n1 = stack_a->array[2];
	if (n1 < n2 && n2 < n3)
		return ;
	else if (n1 > n2 && n1 < n3)
	{
		swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (n1 > n2)
		ft_n1_sup_n2(stack_a, n2, n3);
	else if (n1 < n2)
		ft_n1_inf_n2(stack_a, n1, n3);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	i;
	int	position;

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
