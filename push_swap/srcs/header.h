/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:49:49 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/02/02 21:05:53 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"

# define EMPTY -1

typedef struct s_stack
{
	int	top;
	int	capacity;
	int	*array;
}	t_stack;

long int	ft_atol(char *str);
int			is_valid_argument(int ac, char **av);
int			is_has_duplicate_n(int *arr, int size);
void		swap(t_stack *stack);
void		push(t_stack *stack, int n);
int			pop(t_stack *stack);
t_stack		*ft_create_stack(unsigned int capacity);
int			stack_is_full(t_stack *stack);
int			stack_is_empty(t_stack *stack);
void		rotate(t_stack *stack);
void		rotate_reverse(t_stack *stack);
void		radix_sort(t_stack *stack_a, t_stack *stack_b);
void		quick_sort(int *arr, int start_i, int end_i);
void		ft_intcpy(int *dst, int *src, int size);
void		is_sorted(int *arr, int size);
void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		sort_three(t_stack *stack_a);
void		sort_two(t_stack *stack_a);
void		ft_n1_sup_n2(t_stack *a, int n2, int n3);
void		ft_n1_inf_n2(t_stack *a, int n1, int n3);
int			*get_arr_index(int *arr, int size);
void		push_small_num(t_stack **a, t_stack **b, int pos);
int			get_min_pos(t_stack *a);
void		ft_sort_small_list(int ac, t_stack *a, t_stack *b, int *arr);
void		ft_sort_large_list(int ac, t_stack *a, t_stack *b, int *arr);
int			*check_args(int ac, char **av);

#endif