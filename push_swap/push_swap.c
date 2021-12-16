/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/16 18:36:20 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*check_args(int size, char **av, int *a)
{
	int	i;
	int	j;
	
	if (!is_valid_argument(size, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	a = (int *)malloc((size) * sizeof(int));
	if (!a)
		return (0);
	i = 0;
	j = 1;
	while (i < size)
		a[i++] = ft_atoi(av[j++]);
	if(is_has_duplicate_n(a, size))
	{
		ft_putstr_fd("Error\n", 2);
		free(a);
		exit(0);
	}
	return (a);
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	i;
	
	a = check_args(ac - 1, av, a);
	b = (int *)malloc((ac - 1) * sizeof(int));
	if (!b)
	{
		free(a);
		return (0);
	}
	i = 0;
	while (i < ac - 1)
	{
		printf("%d\n", a[i]);
		i++;
	}
	printf("-------pb------\n");
	a = push(b, a, ac - 1);
	printf("%d", b[0]);
	printf("\n-------a :------\n");
	i = 0;
	while (i < ac - 1)
	{
		printf("%d\n", a[i]);
		i++;
	}
	return (0);
}