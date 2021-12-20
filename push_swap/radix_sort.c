/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:59:08 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/20 03:37:08 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_max(int *arr, int size)
{
	int	max;
	int	i;

	max = arr[0];
	i = 0;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	ft_intcpy(int *dst, int *src, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

void	counting_sort(int *arr, int sig_digit, int size)
{
	int	*output;
	int	*count;
	int	i;
	int	count_size;

	output = (int *)malloc(size * sizeof(int));
	if (!output)
		exit(0);
	count = ft_calloc(10, sizeof(int));
	if(!count)
	{
		free(output);
		exit(0);
	}
	count_size = 10;
	i = 0;
	while (i < size)
		count[(arr[i++] / sig_digit) % 10]++;
	i = 1;
	while (i < count_size)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		output[count[(arr[i] / sig_digit) % 10] - 1] = arr[i];
		// printf("%d\n", arr[i]); /*TO BE DELETED*/
		i--;
	}
	ft_intcpy(arr, output, size);
	free(output);
	free(count);
}

void	radix_sort(int	*arr, t_stack *stack_a, t_stack *stack_b)
{
	int max;
	int	sig_digit;
	(void) stack_b; /*TO BE DELETED*/

	max = get_max(arr, stack_a->capacity);
	sig_digit = 1;
	while (max / sig_digit > 0)
	{
		counting_sort(arr, sig_digit, stack_a->capacity);
		sig_digit *= 10;
	}
}