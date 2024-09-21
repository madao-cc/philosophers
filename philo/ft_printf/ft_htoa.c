/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:49:56 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 12:35:59 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_htoa(unsigned int n)
{
	char			*result;
	unsigned int	digits;
	char			*base;
	unsigned int	temp;

	temp = n;
	base = "0123456789abcdef";
	digits = 0;
	while (temp != 0)
	{
		temp = temp / 16;
		digits++;
	}
	result = malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (0);
	result[digits] = '\0';
	digits--;
	while (n != 0)
	{
		result[digits] = base[n % 16];
		n = n / 16;
		digits--;
	}
	return (result);
}
