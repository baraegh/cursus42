/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:49:49 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/12/20 22:11:55 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# define EMPTY -1

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"
/* TO BE DELETED */
# include <stdio.h>
# include <string.h>
///////////////////

typedef struct s_stack
{
	int	top;
	int	capacity;
	int		*array;
}	t_stack;

long int	ft_atol(const char *str);
int			is_valid_argument(int ac, char **av);
int			is_has_duplicate_n(int *arr, int size);
void		swap(t_stack *stack);
void		push(t_stack *stack, int n);
int			pop(t_stack *stack);
t_stack		*ft_create_stack(unsigned capacity);
int			stack_is_full(t_stack *stack);
int			stack_is_empty(t_stack *stack);
void		rotate(t_stack *stack);
void		rotate_reverse(t_stack *stack);
void		radix_sort(int *arr, t_stack *stack_a, t_stack *stack_b);
void		quick_sort(int *arr, int start_i, int end_i);
void		ft_intcpy(int *dst, int *src, int size);

#endif