/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:07:22 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/10 16:25:18 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_dead(void *p_table)
{
	t_sim	*table;
	int		i;

	i = 0;
	table = (t_sim *)p_table;
	while (check_table_ok(table) == true && i < table->nbr_philos)
	{
		if (check_philo_died(&table->philos[i]) == 1)
		{
			safe_mutex(&table->write_lock, LOCK);
			printf("%zu %d is dead\n", get_current_time() - \
			table->start, table->philos[i].philo_id);
			safe_mutex(&table->write_lock, UNLOCK);
			handle_business(table);
			break ;
		}
		if (i == table->nbr_philos - 1)
			i = -1;
		i++;
		//ft_usleep(100); //! Verificar se é suposto dormir aqui
	}
	return (NULL);
}

void	*monitor_full(void *p_table)
{
	t_sim	*table;
	int		i;

	i = 0;
	table = (t_sim *)p_table;
	while (i < table->nbr_philos)
	{
		if (is_philo_full(&table->philos[i]) == false)
		{
			i = 0;
			ft_usleep(100); //! Verificar se esse valor é o correto
		}
		i++;
	}
	if (check_table_ok(table) == true)
	{
		set_table_on_fire(table);
		handle_business(table);
	}
	return (NULL);
}

//! NOTA:
//! l:14 - l:16 adicionado printf especifico para a ultima cena a ser printada ser philo[i] is dead
//! utils.c - l:53 adicionei a condicao de nao printar se o proprio philo esiver morto
//! Resultou no teste ./philo 4 200 205 200!