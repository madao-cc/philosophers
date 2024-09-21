/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:07:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/10 16:21:04 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_arguments(t_sim *table, char **argv)
{
	table->nbr_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->goal_of_meals = ft_atol(argv[5]);
	else
		table->goal_of_meals = -1;
}

long	ft_atol(char *str)
{
	long	result;
	int		i;

	i = 0;
	result = 0;
	while (ft_is_space(str[i]) == 1)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		ft_error_exit("Error\n The arguments need to be +\n");
	if (ft_is_digit(str[i]) == 0)
		ft_error_exit("Error\n The arguments need to be numbers\n");
	while (ft_is_digit(str[i]) == 1)
		result = (result * 10) + (str[i++] - '0');
	if (result > INT_MAX)
		ft_error_exit("Error\n The arguments need to be \
		smaller than INT_MAX\n");
	return (result);
}

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
