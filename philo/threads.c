/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:09:47 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/10 16:27:07 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_sim *table)
{
	int		i;

	i = 0;
	table->start = get_current_time();
	if (table->goal_of_meals != -1)
	{
		if (pthread_create(&table->mon_full, NULL, &monitor_full, table) != 0)
			return (1);
	}
	while (i < table->nbr_philos)
	{
		if (pthread_create(&table->threads[i], NULL, \
		&philo_routine, &table->philos[i]) != 0)
			return (1);
		i++;
	}
	if (table->nbr_philos != 1)
	{
		if (pthread_create(&table->mon_dead, NULL, &monitor_dead, table) != 0)
			return (1);
	}
	return (0);
}

int	ft_joint_threads(t_sim *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		if (pthread_join(table->threads[i], NULL) != 0)
			return (1);
		i++;
	}
	if (table->goal_of_meals != -1)
		if (pthread_join(table->mon_full, NULL) != 0)
			return (1);
	if (table->nbr_philos != 1)
	{
		if (pthread_join(table->mon_dead, NULL) != 0)
			return (1);
	}
	return (0);
}

void	*philo_routine(void *p_philo)
{
	t_philo		*philo;

	philo = (t_philo *)p_philo;
	get_last_meal_time(philo);
	if (philo->table->nbr_philos == 1)
		handle_1(philo);
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo->table->time_to_eat / 2); //! Check if this is the right value
	while (check_philo_state(philo) != DEAD && \
	check_table_ok(philo->table) == true)
	{
		ft_pickup_forks(philo);
		if (check_philo_state(philo) == DEAD)
			break ;
		ft_eat(philo);
		if (check_philo_state(philo) == DEAD)
			break ;
		ft_sleep(philo);
		if (check_philo_state(philo) == DEAD)
			break ;
		ft_think(philo);
		if (check_philo_state(philo) == DEAD)
			break ;
	}
	return (NULL);
}

void	handle_1(t_philo *philo)
{
	print_message("has taken a fork", philo);
	printf("%zu %d is dead\n", philo->table->time_to_die, philo->philo_id);
	set_philo_state(philo, DEAD);
}
