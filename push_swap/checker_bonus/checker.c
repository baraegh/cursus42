/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:45:40 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/06 17:24:37 by eel-ghan         ###   ########.fr       */
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
	j = stack_a->capacity;
	i = 0;
	while (i < stack_a->capacity)
	{
		push(stack_a, ft_atoi(av[j--]));
		i++;
	}
	if (is_has_duplicate_n(stack_a->array, ac - 1))
	{
		ft_putstr_fd("Error\n", 2);
		free(stack_a);
		exit(0);
	}
	return (stack_a);
}

void	check_action(char *action, t_stack *stack_a,
	t_stack *stack_b)
{
	if (ft_is_equal(action, "sa\n"))
		swap(stack_a);
	else if (ft_is_equal(action, "sb\n"))
		swap(stack_b);
	else if (ft_is_equal(action, "ss\n"))
		swap_a_b(stack_a, stack_b);
	else if (ft_is_equal(action, "pa\n"))
		push(stack_a, pop(stack_b));
	else if (ft_is_equal(action, "pb\n"))
		push(stack_b, pop(stack_a));
	else if (ft_is_equal(action, "ra\n"))
		rotate(stack_a);
	else if (ft_is_equal(action, "rb\n"))
		rotate(stack_b);
	else if (ft_is_equal(action, "rr\n"))
		rotate_a_b(stack_a, stack_b);
	else if (ft_is_equal(action, "rra\n"))
		rotate_reverse(stack_a);
	else if (ft_is_equal(action, "rrb\n"))
		rotate_reverse(stack_b);
	else if (ft_is_equal(action, "rrr\n"))
		rotate_reverse_a_b(stack_a, stack_b);
	else
		error(action, stack_a, stack_b);
}

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	if (!stack_is_empty(stack_b))
		return (0);
	i = 0;
	while (i < stack_a->capacity)
	{
		j = i + 1;
		while (j < stack_a->capacity)
		{
			if (stack_a->array[i] < stack_a->array[j])
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}

void	ft_check_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a, stack_b))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*action;

	if (ac < 2)
		exit(0);
	stack_a = ft_create_stack(ac - 1);
	if (!stack_a)
		exit(0);
	stack_b = ft_create_stack(ac - 1);
	if (!stack_b)
	{
		free(stack_a);
		exit(0);
	}
	stack_a = check_args(ac, av, stack_a);
	action = get_next_line(1);
	while (action && *action != '\n')
	{
		check_action(action, stack_a, stack_b);
		action = get_next_line(1);
	}
	free(action);
	ft_check_stack(stack_a, stack_b);
	return (0);
}
