/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:10:29 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/30 14:21:34 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_set_print(char c, va_list list)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		count += ft_put_uint(va_arg(list, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'x' || c == 'X')
		count += ft_puthexa(va_arg(list, int), c);
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putptr(va_arg(list, unsigned long));
	}
	return (count);
}

int	ft_check(char c)
{
	char	*s;
	int		i;

	s = "cspdiuxX%";
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		list;
	int			i;
	int			count;

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
		else if (*(format) != '%')
			count += ft_putchar(*format);
		format++;
	}
	va_end(list);
	return (count);
}
