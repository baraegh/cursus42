/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:10:29 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/28 16:56:10 by eel-ghan         ###   ########.fr       */
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
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	number = 48 + (n % 10);
	ft_putchar(number);
}

void ft_put_uint(unsigned int n)
{
	if (n < 0)
		n = (UINT_MAX + 1) + n;
	if (n >= 10)
		ft_put_uint(n / 10);
	ft_putchar(48 + (n % 10));
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

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void ft_puthexa(int n, char *s)
{
	unsigned int nb;

	nb = n;
	if (nb < 0)
		nb = (UINT_MAX + 1) + nb;
	if (nb > 15)
		ft_puthexa(nb / 16, s);
	ft_putchar(s[nb % 16]);
}

void	ft_putptr(void *ptr)
{
	ft_putstr("0x7ffe");
	ft_puthexa((unsigned)&(*ptr), "0123456789abcdef");
}

int ft_set_print(char c, va_list list)
{
	char	*x;
	char	*X;

	x = "0123456789abcdef";
	X = "0123456789ABCDEF";
	if (c == 'c')
		ft_putchar(va_arg(list, int));
	else if (c == 's')
		ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		ft_put_uint(va_arg(list, unsigned int));
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'x')
		ft_puthexa(va_arg(list, int), x);
	else if (c == 'X')
		ft_puthexa(va_arg(list, int), X);
	else if (c == 'p')
		ft_putptr(va_arg(list, void *));
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


int main()
{
	int n = 2;
	int *p = &n;

	ft_printf("test : %p", p);
	printf("\ntest : %p", p);
	// printf("\ntest : 0x%u", (unsigned)&(*p));
}