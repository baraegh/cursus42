/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:10:29 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/28 19:36:03 by eel-ghan         ###   ########.fr       */
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

int	ft_putnbr(int nb)
{
	char	number;
	long	n;
	int		count;

	n = nb;
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	number = 48 + (n % 10);
	count += ft_putchar(number);
	return (count);
}

int ft_put_uint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_uint(n / 10);
	count += ft_putchar(48 + (n % 10));
	return (count);
}

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
		return (ft_putstr("(null)"));
	count = 0;
	while (*str != '\0')
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int ft_puthexa(unsigned int n, char *s)
{
	int count;

	count = 0;
	if (n > 15)
		count += ft_puthexa(n / 16, s);
	count += ft_putchar(s[n % 16]);
	return (count);
}

int	ft_putptr(unsigned long int n, char *s)
{
	int count;

	count = 0;
	if (n > 15)
		count += ft_putptr(n / 16, s);
	count += ft_putchar(s[n % 16]);
	return (count);
}

int ft_set_print(char c, va_list list)
{
	char	*x;
	char	*X;
	int		count;

	x = "0123456789abcdef";
	X = "0123456789ABCDEF";
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
	else if (c == 'x')
		count += ft_puthexa(va_arg(list, int), x);
	else if (c == 'X')
		count += ft_puthexa(va_arg(list, int), X);
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putptr(va_arg(list, unsigned long), x);
	}
	return (count);
}

int ft_check(char c)
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
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(list);
	return (count);
}


// int main()
// {
// 	// int n = 2;
// 	// int *p = &n;

// 	// ft_printf("test : %x", -123);
// 	// printf("\ntest : %x", -123);
// 	printf("\n->%d\n",ft_printf("test : %s", NULL));
// 	printf("\n->%d",printf("test : %s", NULL));
// 	// printf("\ntest : 0x%u", (unsigned)&(*p));
// }