/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/31 21:51:43 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*check_args(int ac, char **av)
{
	int	j;
	int	i;
	int	*arr;

	if (!is_valid_argument(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	arr = (int *)malloc((ac -1) * sizeof(int));
	if (!arr)
		exit(0);
	j = 1;
	i = 0;
	while (i < ac - 1)
		arr[i++] = ft_atoi(av[j++]);
	if (is_has_duplicate_n(arr, ac - 1))
	{
		ft_putstr_fd("Error\n", 2);
		free(arr);
		exit(0);
	}
	return (arr);
}

static int	*ft_get_index(int *tmp_arr, int *arr,
	int *arr_index, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tmp_arr[i] == arr[j])
				arr_index[i] = j;
			j++;
		}
		i++;
	}
	free(tmp_arr);
	return (arr_index);
}

int	*get_arr_index(int *arr, int size)
{
	int	*arr_index;
	int	*tmp_arr;

	tmp_arr = (int *)malloc(size * sizeof(int));
	if (!tmp_arr)
		return (NULL);
	ft_intcpy(tmp_arr, arr, size);
	quick_sort(arr, 0, size - 1);
	arr_index = (int *)malloc(size * sizeof(int));
	if (!arr_index)
		return (NULL);
	arr_index = ft_get_index(tmp_arr, arr, arr_index, size);
	return (arr_index);
}

static void	ft_sort_stack_a(int ac, t_stack *stack_a,
	t_stack *stack_b, int *arr)
{
	int		*arr_index;
	int		i;

	if (ac == 6)
	{
		sort_five(stack_a, stack_b, arr);
		exit(0);
	}
	arr_index = get_arr_index(arr, ac - 1);
	if (!arr_index)
	{
		free(arr);
		free(stack_a);
		free(stack_b);
		exit(0);
	}
	i = stack_a->capacity - 1;
	while (i >= 0)
		push(stack_a, arr_index[i--]);
	free(arr_index);
	radix_sort(stack_a, stack_b);
	i = stack_a->capacity - 1;
	while (i >= 0)
		push(stack_a, arr[i--]);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;

	if (ac == 1)
		return (0);
	arr = check_args(ac, av);
	is_sorted(arr, ac - 1);
	stack_a = ft_create_stack(ac - 1);
	if (!stack_a)
	{
		free(arr);
		exit (0);
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
