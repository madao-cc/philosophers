/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:50:11 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 12:07:56 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list list, const char c)
{
	unsigned int	size;

	size = 0;
	if (c == 'c')
		size = size + ft_printchar(va_arg(list, int));
	else if (c == 's')
		size = size + ft_printstr(va_arg(list, char *));
	else if (c == 'i' || c == 'd')
		size = size + ft_printnbr(va_arg(list, int));
	else if (c == 'p')
		size = size + ft_printptr(va_arg(list, unsigned long long));
	else if (c == 'x')
		size = size + ft_printhex(va_arg(list, unsigned int));
	else if (c == 'X')
		size = size + ft_printbighex(va_arg(list, unsigned int));
	else if (c == '%')
		size = size + ft_printpercent();
	else if (c == 'u')
		size = size + ft_printunsigned(va_arg(list, unsigned int));
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list			list;
	unsigned int	i;
	unsigned int	size;

	va_start(list, format);
	i = 0;
	size = 0;
	if (format[i] == '\0')
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			size = size + ft_check(list, format[i + 1]);
			i++;
		}
		else
			size = size + ft_printchar(format[i]);
		i++;
	}
	va_end(list);
	return (size);
}
