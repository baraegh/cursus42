/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/20 03:42:14 by eel-ghan         ###   ########.fr       */
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

int	*get_arr_index(t_stack *stack)
{
	int *arr;
	int	*arr_index;
	int	i;
	int	j;

	arr = (int *)malloc(stack->capacity * sizeof(int));
	if (!arr)
		return (NULL);
	ft_intcpy(arr, stack->array, stack->capacity);
	quick_sort(arr, 0, stack->top);
	arr_index = (int *)malloc(stack->capacity * sizeof(int));
	if (!arr_index)
		return (NULL);
	i = 0;
	while (i < (int)stack->capacity)
	{
		j = 0;
		while (j < (int)stack->capacity)
		{
			if (arr[i] == stack->array[j])
				arr_index[i] = j;
			j++;
		}
		i++;
	}
	stack->array = arr;
	return (arr_index);
}

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		*arr;
	int		*tmp_arr_a;
	// unsigned int	i; /*TO BE DELETED*/
	
	stack_a = check_args(ac, av);
	stack_b = ft_create_stack(ac - 1);
	if (!stack_b)
		exit(0);
	arr = get_arr_index(stack_a);
	if (!arr)
	{
		free(stack_a);
		free(stack_b);
		exit(0);
	}
	tmp_arr_a = (int *)malloc(stack_a->capacity * sizeof(int));
	if (!tmp_arr_a)
	{
		free(stack_a);
		free(stack_b);
		exit(0);
	}
	ft_intcpy(tmp_arr_a, stack_a->array, stack_a->capacity);
	radix_sort(arr, stack_a, stack_b);
	stack_a->array = tmp_arr_a;
	/*TO BE DELETED*/
	// i = 0;
	// while (i < stack_a->capacity)
	// {
		printf("%d \n", stack_a->array[stack_a->top]);
	// 	i++;
	// }
	//////////////////
	free(tmp_arr_a);
	return (0);
}