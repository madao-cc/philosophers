/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:07:13 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/10 16:07:14 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_mutex(pthread_mutex_t *mutex, t_code code)
{
	if (code == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			ft_error_exit("Error\n Somewhere while locking a mutex.\n");
	}
	if (code == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			ft_error_exit("Error\n Somewhere while unlocking a mutex.\n");
	}
	if (code == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			ft_error_exit("Error\n Somewhere while initiating a mutex.\n");
	}
	if (code == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			ft_error_exit("Error\n Somewhere while destroying a mutex.\n");
	}
}

void	ft_error_exit(char *error)
{
	ft_printf("%s", error);
	exit(EXIT_FAILURE);
}

void	ft_nuke_all(t_sim *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		safe_mutex(&table->philos[i].mtx_philo_state, DESTROY);
		safe_mutex(&table->philos[i].mtx_last_meal_time, DESTROY);
		safe_mutex(&table->philos[i].mtx_meal_counter, DESTROY);
		safe_mutex(&table->forks[i], DESTROY);
		i++;
	}
	safe_mutex(&table->write_lock, DESTROY);
	safe_mutex(&table->mtx_end_sim, DESTROY);
	safe_mutex(&table->mtx_full, DESTROY);
	free(table->forks);
	free(table->threads);
	free(table->philos);
}
