/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/18 18:13:24 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*check_args(int ac, char **av)
{
	int		j;
	t_stack	*stack;

	if (!is_valid_argument(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	stack = ft_create_stack(ac - 1);
	if (!stack)
		return (0);
	j = ac - 1;
	while (j >= 0)
		push(stack, ft_atoi(av[j--]));
	if(is_has_duplicate_n(stack, ac - 1))
	{
		ft_putstr_fd("Error\n", 2);
		free(stack);
		exit(0);
	}
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = check_args(ac, av);
	stack_b = ft_create_stack(ac - 1);
	
	return (0);
}