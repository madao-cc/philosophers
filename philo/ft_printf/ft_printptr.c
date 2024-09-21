/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:50:33 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 11:59:38 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long n)
{
	char			*nbr;
	unsigned int	size;

	if (n == 0)
	{
		write(STDERR_FILENO, "(nil)", 5);
		return (5);
	}
	else
	{
		write(STDERR_FILENO, "0x", 2);
		size = 2;
		nbr = ft_createptr(n);
		ft_printstr(nbr);
		size = size + ft_strlen(nbr);
		free(nbr);
		return (size);
	}
}
