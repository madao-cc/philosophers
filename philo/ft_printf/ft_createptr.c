/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:49:48 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 11:57:17 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_createptr(unsigned long long n)
{
	char				*result;
	unsigned int		digits;
	char				*base;
	unsigned long long	temp;

	digits = 0;
	temp = n;
	base = "0123456789abcdef";
	while (temp != 0)
	{
		digits++;
		temp = temp / 16;
	}
	result = malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (0);
	result[digits--] = '\0';
	while (n != 0)
	{
		result[digits--] = base[n % 16];
		n = n / 16;
	}
	return (result);
}
