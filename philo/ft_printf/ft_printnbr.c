/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:50:25 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 12:03:25 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	unsigned int	size;
	char			*nbr;

	if (n == -2147483648)
	{
		write(STDERR_FILENO, "-2147483648", 11);
		size = 11;
		return (size);
	}
	if (n == 0)
	{
		write(STDERR_FILENO, "0", 1);
		return (1);
	}
	else
	{
		nbr = ft_itoa(n);
		ft_printstr(nbr);
		size = ft_strlen(nbr);
		free(nbr);
		return (size);
	}
}
