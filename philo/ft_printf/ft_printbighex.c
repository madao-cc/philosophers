/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbighex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:50:22 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 12:41:43 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printbighex(unsigned int n)
{
	char			*nbr;
	unsigned int	size;

	size = 0;
	if (n == 0)
	{
		write (STDERR_FILENO, "0", 1);
		size = 1;
		return (size);
	}
	nbr = ft_bightoa(n);
	ft_printstr(nbr);
	size = size + ft_strlen(nbr);
	free(nbr);
	return (size);
}
