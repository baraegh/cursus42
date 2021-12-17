/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/17 23:22:40 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*check_args(int size, char **av, t_stack *stack_a)
{
	int	i;
	int	j;
	
	if (!is_valid_argument(size, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	stack_a = ft_create_stack(size);
	if (!stack_a)
		return (0);
	j = 1;
	while (j <= size)
		push(stack_a, ft_atoi(av[j++]));
	if(is_has_duplicate_n(stack_a, size))
	{
		ft_putstr_fd("Error\n", 2);
		free(stack_a);
		exit(0);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int	i  = 0; // TO BE DELETED

	stack_a = check_args(ac - 1, av, stack_a);
	// TO BE DELETED
	while (i < ac -1)
	{
		printf("%d\n", stack_a->array[i]);
		i++;
	}
	////////////////
	return (0);
}