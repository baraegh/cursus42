/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:49:49 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/16 18:34:19 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"
/* TO BE DELETED */
# include <stdio.h>
# include <string.h>
///////////////////

long int	ft_atol(const char *str);
int			is_valid_argument(int ac, char **av);
int			is_has_duplicate_n(int *tab, int size);
void		swap(int *tab);
int		    *push(int *dst, int *src, int size);

#endif