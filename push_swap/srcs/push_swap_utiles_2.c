/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:05:23 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/02/02 21:02:14 by eel-ghan         ###   ########.fr       */
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

void	ft_sort_small_list(int ac, t_stack *a, t_stack *b, int *arr)
{
	int	i;

	i = a->capacity - 1;
	while (i >= 0)
		push(a, arr[i--]);
	if (ac - 1 == 2)
		sort_two(a);
	if (ac - 1 == 3)
		sort_three(a);
	else if (ac - 1 <= 5)
		sort_five(a, b);
}

void	ft_sort_large_list(int ac, t_stack *a, t_stack *b, int *arr)
{
	int		*arr_index;
	int		i;

	arr_index = get_arr_index(arr, ac - 1);
	if (!arr_index)
	{
		free(arr);
		free(a);
		free(b);
		exit(0);
	}
	i = a->capacity - 1;
	while (i >= 0)
		push(a, arr_index[i--]);
	free(arr_index);
	radix_sort(a, b);
	free(a);
	i = a->capacity - 1;
	while (i-- >= 0)
		pop(a);
	i = a->capacity - 1;
	while (i >= 0)
		push(a, arr[i--]);
}

int	*ft_get_index(int *tmp_arr, int *arr,
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
	free(tmp_arr);
	return (arr_index);
}
