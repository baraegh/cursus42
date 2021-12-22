/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:45:40 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/23 00:24:43 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/header.h"

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

int	main(int ac, char **av)
{
	char	*buf;
	char	*operations;
	int		read_bytes;
	int		i;

	if (check_args(ac, av))
		exit (0);
	read_bytes = 1;
	buf = (char *)malloc(4);
	if (!buf)
		exit(0);
	operations = (char *)malloc(4);
	if (!operations)
		exit(0);
	
	while (read_bytes)
	{
		read_bytes = read(0, buf, 3);
		if (read_bytes == -1)
			exit(0);
		buf[read_bytes] = '\0';
		if (!*operations)
			operations[0] = '\0';
		ft_strjoin(operations, buf);
	}
	i = 0;
	while (operations[i])
		printf("%c", operations[i++]);
	return (0);	
}