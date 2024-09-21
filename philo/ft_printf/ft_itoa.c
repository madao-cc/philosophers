/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:50:04 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 10:53:43 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char				*result;
	unsigned int		digits;
	int					nbr;

	nbr = n;
	digits = ft_getdigits(n);
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	result = malloc(sizeof(char) * digits + 1);
	if (!result)
		return (0);
	result[digits] = '\0';
	digits--;
	while (n != 0)
	{
		result[digits] = n % 10 + '0';
		n = n / 10;
		digits--;
	}
	if (nbr < 0)
		result[0] = '-';
	return (result);
}
