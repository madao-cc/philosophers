/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:21:26 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 12:41:10 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	unsigned int	size;
	unsigned int	temp;

	size = 0;
	temp = n;
	if (n == 0)
	{
		write(STDERR_FILENO, "0", 1);
		size = 1;
		return (size);
	}
	while (temp != 0)
	{
		size++;
		temp = temp / 10;
	}
	ft_putunsigned(n);
	return (size);
}
