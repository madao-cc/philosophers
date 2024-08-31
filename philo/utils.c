#include "philo.h"

int	ft_usleep(size_t milisseconds)
{
	size_t	start;
	start = get_current_time();
	while((get_current_time() - start) < milisseconds)
		usleep(1000);
	return(0);
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
	if (get_current_time() - philo->last_meal_time >= philo->table->time_to_die && check_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		return (1);
	}
	return (0);
}

int	check_all_full(t_sim *table)
{
	int	i;
	int	fat_counter;
	t_philo	*philo;

	i = 0;
	fat_counter = 0;
	if (table->goal_of_meals == -1)
		return (0);
	while (i < table->nbr_philos)
	{
		philo = &table->philos[i];
		safe_mutex(&table->philos[i].mtx_meal_counter, LOCK);
		if (table->philos[i].meal_counter == table->goal_of_meals && check_philo_state(philo) != DEAD)
			fat_counter++;
		safe_mutex(&table->philos[i].mtx_meal_counter, UNLOCK);
		i++;
	}
	if (fat_counter == table->nbr_philos)
	{
		handle_business(table);
		return (1);
	}
	return (0);
}

void	print_message(char *str, t_philo *philo)
{
	long	time;

	safe_mutex(&philo->table->write_lock, LOCK);
	time = get_current_time();
	if (philo->table->end_sim == false)
		printf("%zu %d %s\n", (time - philo->table->start), philo->philo_id, str);
	safe_mutex(&philo->table->write_lock, UNLOCK);
}

void	get_last_meal_time(t_philo *philo)
{
	safe_mutex(&philo->mtx_last_meal_time, LOCK);
	philo->last_meal_time = get_current_time();
	safe_mutex(&philo->mtx_last_meal_time, UNLOCK);
}

int	check_table_ok(t_sim *table)
{
	safe_mutex(&table->mtx_end_sim, LOCK);
	if (table->end_sim == true)
	{
		safe_mutex(&table->mtx_end_sim, UNLOCK);
		return (0);
	}
	safe_mutex(&table->mtx_end_sim, UNLOCK);
	return (1);
}
