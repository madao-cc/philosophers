/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:49:43 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 11:49:06 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = 0;
	if (!str)
	{
		write(STDERR_FILENO, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
		size++;
	}
	return (size);
}
