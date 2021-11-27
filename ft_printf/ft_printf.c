/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:10:29 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/27 20:49:15 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int nb)
{
	char	number;
	long	n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	number = 48 + (n % 10);
	ft_putchar(number);
	// write(1, &number, 1);
}

int ft_check(char c)
{
	char	s[] = "cspdiuxX%";
	int		i;
	// s = "cspdiuxX%";
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int ft_set_print(char c, va_list list)
{
	if (c == 'c')
		ft_putchar(va_arg(list, int));
	else if (c == 's')
		ft_putstr(va_arg(list, char *));

	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		list;
	int			i;
	int			str_len;
	int			count;
	
	// str_len = ft_strlen(format);
	va_start(list, format);
	i = 0;
	count = 0;
	while (*format)
	{
		if (*format == '%' && ft_check(*(format + 1)))
		{	
			count += ft_set_print(*(format + 1), list);
			format++;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(list);
	return (count);
}


int main()
{
	ft_printf("%%");
	// printf("\n%s", "abc");
}