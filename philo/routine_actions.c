/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:09:39 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/10 16:19:51 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	if (check_philo_state(philo) == DEAD)
		return ;
	set_philo_state(philo, THINKING);
	print_message("is thinking", philo);
}

void	ft_sleep(t_philo *philo)
{
	if (check_philo_state(philo) == DEAD)
		return ;
	set_philo_state(philo, SLEEPING);
	print_message("is sleeping", philo);
	ft_usleep(philo->table->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	if (check_philo_state(philo) == DEAD)
		return ;
	set_philo_state(philo, EATING);
	print_message("is eating", philo);
	ft_usleep(philo->table->time_to_eat);
	ft_drop_forks(philo);
	safe_mutex(&philo->mtx_meal_counter, LOCK);
	philo->meal_counter++;
	safe_mutex(&philo->mtx_meal_counter, UNLOCK);
	get_last_meal_time(philo);
}

void	ft_pickup_forks(t_philo *philo)
{
	if (check_philo_state(philo) == DEAD && \
	check_table_ok(philo->table) == false)
		return ;
	safe_mutex(philo->left_fork, LOCK);
	print_message("has taken a fork", philo);
	if (philo->table->nbr_philos == 1)
	{
		safe_mutex(philo->left_fork, UNLOCK);
		ft_usleep(philo->table->time_to_die);
		set_philo_state(philo, DEAD);
		return ;
	}
	if (check_philo_state(philo) == DEAD || \
	check_table_ok(philo->table) == false)
		return (safe_mutex(philo->left_fork, UNLOCK));
	safe_mutex(philo->right_fork, LOCK);
	if (check_philo_state(philo) == DEAD || \
	check_table_ok(philo->table) == false)
	{
		ft_drop_forks(philo);
		return ;
	}
	if (check_philo_state(philo) != DEAD && \
	check_table_ok(philo->table) == true)
		print_message("has taken a fork", philo);
}

void	ft_drop_forks(t_philo *philo)
{
	safe_mutex(philo->right_fork, UNLOCK);
	safe_mutex(philo->left_fork, UNLOCK);
}
