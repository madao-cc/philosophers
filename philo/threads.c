#include "philo.h"

int	ft_create_threads(t_sim *table)
{
	int		i;

	i = 0;
	table->start = get_current_time();
	while (i < table->nbr_philos)
	{
		if (pthread_create(&table->threads[i], NULL, &philo_routine, &table->philos[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&table->observer, NULL, &monitor, table) != 0)
		return (1);
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
	if (pthread_join(table->observer, NULL) != 0)
		return (1);
	return (0);
}

void	*philo_routine(void *p_philo)
{
	t_philo		*philo;
	
	philo = (t_philo *)p_philo;
	get_last_meal_time(philo);
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo->table->time_to_eat); //TODO: Check if this is the right value
	while (check_philo_state(philo) != DEAD && check_table_ok(philo->table) == 1)
	{
		ft_pickup_forks(philo);
		if (check_philo_state(philo) == DEAD)
			break ;
		ft_eat(philo);
		if (check_philo_state(philo) == DEAD)
			break ;
		ft_drop_forks(philo);
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

void	*monitor(void *p_table)
{
	t_sim 		*table;
	int			i;

	i = 0;
	table = (t_sim *)p_table;
	while (check_table_ok(table) == 1 && i < table->nbr_philos)
	{
		if (check_philo_died(&table->philos[i]) == 1)
		{
			print_message("died", &table->philos[i]);
			handle_business(table);
			break;
		}
		if (check_all_full(table) == 1)
		{
			handle_business(table);
			break;
		}
		if (i == table->nbr_philos - 1)
			i = -1;
		i++;
		ft_usleep(100); //! Verificar se esse valor é o correto
	}
	return (NULL);
}
