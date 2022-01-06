/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:56:14 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/01/06 17:26:34 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"

# define EMPTY -1

typedef struct s_stack
{
	int	top;
	int	capacity;
	int	*array;
}	t_stack;

int			is_valid_argument(int ac, char **av);
long int	ft_atol(char *str);
int			stack_is_full(t_stack *stack);
int			stack_is_empty(t_stack *stack);
int			is_has_duplicate_n(int *arr, int size);
t_stack		*ft_create_stack(unsigned int capacity);
int			stack_is_empty(t_stack *stack);
void		push(t_stack *stack, int n);
int			pop(t_stack *stack);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		rotate_reverse(t_stack *stack);
void		swap_a_b(t_stack *stack_a, t_stack *stack_b);
void		rotate_a_b(t_stack *stack_a, t_stack *stack_b);
void		rotate_reverse_a_b(t_stack *stack_a, t_stack *stack_b);
int			ft_is_equal(char *s1, char *s2);
void		error(char *s, t_stack *stack_a, t_stack *stack_b);

#endif