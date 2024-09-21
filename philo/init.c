/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:07:19 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/10 16:07:20 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_sim *table)
{
	safe_mutex(&table->write_lock, INIT);
	safe_mutex(&table->mtx_end_sim, INIT);
	safe_mutex(&table->mtx_full, INIT);
	table->end_sim = false;
	table->threads = malloc(sizeof(pthread_t) * table->nbr_philos);
	if (table->threads == NULL)
		exit(EXIT_FAILURE);
	table->philos = malloc(sizeof(t_philo) * table->nbr_philos);
	if (table->philos == NULL)
	{
		free(table->threads);
		exit(EXIT_FAILURE);
	}
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
	if (table->forks == NULL)
	{
		free(table->threads);
		free(table->philos);
		exit(EXIT_FAILURE);
	}
	ft_init_philos(table);
	ft_init_forks(table);
}

void	ft_init_forks(t_sim *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		safe_mutex(&(table->forks[i]), INIT);
		i++;
	}
	i = 0;
	while (i < table->nbr_philos)
	{
		ft_assemble_forks(table, i);
		i++;
	}
}

void	ft_assemble_forks(t_sim *table, int i)
{
	if (i == 0)
	{
		table->philos[i].left_fork = &table->forks[0];
		table->philos[i].right_fork = &table->forks[table->nbr_philos - 1];
	}
	else
	{
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[i - 1];
	}
}

void	ft_init_philos(t_sim *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		table->philos[i].table = table;
		table->philos[i].philo_id = i + 1;
		table->philos[i].meal_counter = 0;
		table->philos[i].state = IDLE;
		safe_mutex(&(table->philos[i].mtx_philo_state), INIT);
		safe_mutex(&(table->philos[i].mtx_last_meal_time), INIT);
		safe_mutex(&(table->philos[i].mtx_meal_counter), INIT);
		i++;
	}
}
