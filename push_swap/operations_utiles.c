/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:54:36 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/16 23:27:00 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(int *tab)
{
    int	tmp;

	if (!tab[0] || !tab[1])
		return ;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

static int	*ft_intcopy(int *dst, int *src, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

// int		*push(int *dst, int **src, int size)
// {
// 	int	*tmp;
// 	int	i;
	
// 	if(size == 1)
// 	{
// 		dst = malloc(size * sizeof(int));
// 		if (!dst)
// 			return (0);
// 		dst[0] = *src[0];
// 	}
// 	else
// 	{
// 		// tmp = (int *)malloc((size - 1) * sizeof(int));
// 		tmp = (int *)malloc(size(dst) * sizeof(int));
// 		if (!tmp)
// 			return(0);
// 		ft_intcopy(tmp, dst, size - 1);
// 		dst = (int *)malloc(size * sizeof(int));
// 		if (!dst)
// 			return (0);
// 		dst[0] = *src[0];
// 		ft_intcopy(dst + 1, tmp, size - 1);
// 	}1
// 	tmp = (int *)malloc((size - 1) * sizeof(int));
// 	ft_intcopy(tmp, src + 1, size - 1);
// 	src = (int *)malloc((size - 1) * sizeof(int));
// 	ft_intcopy(src, tmp, size - 1);
// 	free(tmp);
// 	return (dst);
// }

int	*push(int *dst, int *src, int size)
{
	int	*tmp;
	int	i;

	
	tmp = (int *)malloc((size - 1) * sizeof(int));
	if (!tmp)
		return (0);
	ft_intcopy(tmp, dst, size - 1);
	dst[0] = src[0];
	ft_intcopy(dst + 1, tmp, size - 1);

	tmp = (int *)malloc((size - 1) * sizeof(int));
	if (!tmp)
		return (0);
	ft_intcopy(tmp, src + 1, size - 1);
	src = (int *)malloc((size - 1) * sizeof(int));
	if (!src)
		return (0);
	ft_intcopy(src, tmp, size - 1);
	free(tmp);
	return (src);
}