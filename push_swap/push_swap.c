/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:35:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/15 13:52:37 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*check_args(int ac, char **av, int *a)
{
	int	i;
	int	j;
	
	if (!is_valid_argument(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	a = malloc((ac - 1) * sizeof(int));
	if (!a)
		return (0);
	i = 0;
	j = 1;
	while (i < ac - 1)
		a[i++] = ft_atoi(av[j++]);
	if(is_has_duplicate_n(a, ac - 1))
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

	a = check_args(ac, av, a);
	b = malloc((ac - 1) * sizeof(int));
	if (!b)
	{
		free(a);
		return (0);
	}
	printf("yup");
	
	return (0);
}