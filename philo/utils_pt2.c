/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:47 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/10 16:23:17 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo)
{
	long	time;

	safe_mutex(&philo->table->write_lock, LOCK);
	time = get_current_time();
	if (check_table_ok(philo->table) == true && \
	check_philo_state(philo) != DEAD)
		printf("%zu %d %s\n", (time - philo->table->start), \
		philo->philo_id, str);
	safe_mutex(&philo->table->write_lock, UNLOCK);
}

void	get_last_meal_time(t_philo *philo)
{
	safe_mutex(&philo->mtx_last_meal_time, LOCK);
	philo->last_meal_time = get_current_time();
	safe_mutex(&philo->mtx_last_meal_time, UNLOCK);
}
