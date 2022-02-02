/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/02/02 21:03:54 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/header.h"

void	ft_sort_stack_a(int ac, t_stack *a, t_stack *b, int *arr)
{
	if (ac <= 6)
		ft_sort_small_list(ac, a, b, arr);
	else
		ft_sort_large_list(ac, a, b, arr);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;

	if (ac == 1)
		exit(0);
	arr = check_args(ac, av);
	is_sorted(arr, ac - 1);
	stack_a = ft_create_stack(ac - 1);
	if (!stack_a)
	{
		free(arr);
		exit(0);
	}
	stack_b = ft_create_stack(ac - 1);
	if (!stack_b)
	{
		free(arr);
		free(stack_a);
		exit(0);
	}
	ft_sort_stack_a(ac, stack_a, stack_b, arr);
	free(arr);
	return (0);
}
