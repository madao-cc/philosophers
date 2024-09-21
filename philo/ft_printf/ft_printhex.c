/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:50:18 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 12:51:05 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n)
{
	char			*nbr;
	unsigned int	size;

	size = 0;
	if (n == 0)
	{
		write(STDERR_FILENO, "0", 1);
		size = 1;
		return (size);
	}
	nbr = ft_htoa(n);
	size = size + ft_printstr(nbr);
	free(nbr);
	return (size);
}
