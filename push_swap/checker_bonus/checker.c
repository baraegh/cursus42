/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:45:40 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/03 19:17:15 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/header.h"

t_stack	*check_args(int ac, char **av, t_stack *stack_a)
{
	int	j;
	int	i;

	if (!is_valid_argument(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		free(stack_a);
		exit(0);
	}
	j = 1;
	i = 0;
	while (i < ac - 1)
		push(stack_a, ft_atoi(av[j++]));
	if (is_has_duplicate_n(stack_a->array, ac - 1))
	{
		ft_putstr_fd("Error\n", 2);
		free(stack_a);
		exit(0);
	}
	i = 0;
	while (i < ac)
		printf("%d", stack_a->array[i++]);
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	// char	*operations;
	// int		i;

	stack_a = ft_create_stack(ac - 1);
	if (!stack_a)
		exit(0);
	if (check_args(ac, av, stack_a))
		exit (0);
	
	return (0);	
}