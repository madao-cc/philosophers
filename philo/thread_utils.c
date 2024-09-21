/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:09:44 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/10 16:26:16 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	check_philo_state(t_philo *philo)
{
	t_state	state;

	safe_mutex(&philo->mtx_philo_state, LOCK);
	state = philo->state;
	safe_mutex(&philo->mtx_philo_state, UNLOCK);
	return (state);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	safe_mutex(&philo->mtx_philo_state, LOCK);
	if (philo->state != DEAD)
		philo->state = state;
	safe_mutex(&philo->mtx_philo_state, UNLOCK);
}

void	handle_business(t_sim *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		safe_mutex(&table->philos[i].mtx_philo_state, LOCK);
		table->philos[i].state = DEAD;
		safe_mutex(&table->philos[i].mtx_philo_state, UNLOCK);
		i++;
	}
	set_table_on_fire(table);
}

bool	check_table_ok(t_sim *table)
{
	safe_mutex(&table->mtx_end_sim, LOCK);
	if (table->end_sim == true)
	{
		safe_mutex(&table->mtx_end_sim, UNLOCK);
		return (false);
	}
	safe_mutex(&table->mtx_end_sim, UNLOCK);
	return (true);
}

void	set_table_on_fire(t_sim *table)
{
	safe_mutex(&table->mtx_end_sim, LOCK);
	table->end_sim = true;
	safe_mutex(&table->mtx_end_sim, UNLOCK);
}
