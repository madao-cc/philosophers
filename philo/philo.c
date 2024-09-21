/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:07:26 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/21 15:03:06 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim	table;

	if (argc == 5 || argc == 6)
	{
		ft_check_arguments(&table, argv);
		ft_init(&table);
		if (ft_create_threads(&table) == 1)
			ft_nuke_all(&table);
		if (ft_joint_threads(&table) == 1)
			ft_nuke_all(&table);
		ft_nuke_all(&table);
		return (0);
	}
	else
		ft_error_exit("Error\n Your arguments just don't make sense!\n");
}
