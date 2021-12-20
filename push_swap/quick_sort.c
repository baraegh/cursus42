/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:44:32 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/20 01:28:18 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_partition(int *arr, int start_i, int end_i)
{
	int	pivot;
	int	i;
	int	j;
	
	pivot = arr[end_i];
	j = start_i;
	i = start_i;
	while (i < end_i)
	{
		if (arr[i] < pivot)
		{
			ft_swap(&arr[j], &arr[i]);
			j++;
		}
		i++;
	}
	ft_swap(&arr[j], &arr[end_i]);
	return (j);
}

void	quick_sort(int *arr, int start_i, int end_i)
{
	int pivot_i;

	if (start_i > end_i)
		return ;
	pivot_i = ft_partition(arr, start_i, end_i);
	quick_sort(arr, start_i, pivot_i - 1);
	quick_sort(arr, pivot_i + 1, end_i);
}