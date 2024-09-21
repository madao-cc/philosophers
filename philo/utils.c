/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:09:59 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/21 15:33:40 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milisseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milisseconds)
		usleep(1000);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	check_philo_died(t_philo *philo)
{
	if (philo->table->nbr_philos == 1)
		return (0);
	safe_mutex(&philo->mtx_last_meal_time, LOCK);
	if (get_current_time() - philo->last_meal_time >= \
	philo->table->time_to_die && check_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		safe_mutex(&philo->mtx_last_meal_time, UNLOCK);
		return (1);
	}
	safe_mutex(&philo->mtx_last_meal_time, UNLOCK);
	return (0);
}

bool	is_philo_full(t_philo *philo)
{
	if (philo->table->goal_of_meals == -1)
		return (false);
	safe_mutex(&philo->mtx_meal_counter, LOCK);
	if (philo->meal_counter >= philo->table->goal_of_meals)
	{
		safe_mutex(&philo->mtx_meal_counter, UNLOCK);
		return (true);
	}
	safe_mutex(&philo->mtx_meal_counter, UNLOCK);
	return (false);
}
