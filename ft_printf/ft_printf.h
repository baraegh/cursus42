/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:16:00 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/28 15:37:11 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
/* TO BE DELETED */
#include <stdio.h>
/*################*/

int ft_printf(const char *, ...);

#endif