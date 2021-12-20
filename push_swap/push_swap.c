/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/20 23:08:00 by eel-ghan         ###   ########.fr       */
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
	if(is_has_duplicate_n(arr, ac - 1))
	{
		ft_putstr_fd("Error\n", 2);
		free(arr);
		exit(0);
	}
	return (arr);
}

/* TO BE DELETED */
int	*ft_reverse_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
	return (arr);
}
//////////////////////////////////////////

int	*get_arr_index(int *arr, int size)
{
	int	*arr_index;
	int	*tmp_arr;
	int	i;
	int	j;

	tmp_arr = (int *)malloc(size * sizeof(int));
	if (!tmp_arr)
		return (NULL);
	ft_intcpy(tmp_arr, arr, size);
	quick_sort(arr, 0, size - 1);
	arr_index = (int *)malloc(size * sizeof(int));
	if (!arr_index)
		return (NULL);
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

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		*arr;
	int		*arr_index;
	// int	i; /*TO BE DELETED*/
	
	arr = check_args(ac, av);
	arr_index = get_arr_index(arr, ac - 1);
	if (!arr_index)
	{
		free(arr);
		free(arr_index);
		exit(0);
	}
	stack_a = ft_create_stack(ac - 1);
	if (!stack_a)
		exit (0);
	stack_b = ft_create_stack(ac - 1);
	if (!stack_b)
		exit(0);
	// radix_sort(arr, stack_a, stack_b);

	/*TO BE DELETED*/
	// i = 0;
	// while (i < (int)stack_a->capacity)
	// {
	// 	printf("%d \n", arr[i]);
	// 	i++;
	// }
	//////////////////

	// stack_a->array = arr;
	free(stack_b);
	free(arr);
	free(arr_index);
	return (0);
}