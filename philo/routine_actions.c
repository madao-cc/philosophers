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
	safe_mutex(&philo->mtx_meal_counter, LOCK);
	philo->meal_counter++;
	safe_mutex(&philo->mtx_meal_counter, UNLOCK);
	ft_usleep(philo->table->time_to_eat);
	get_last_meal_time(philo);
}

void	ft_pickup_forks(t_philo *philo)
{
	if (check_philo_state(philo) == DEAD)
		return ;
	safe_mutex(philo->left_fork, LOCK);
	print_message("has taken a fork", philo);
	if (philo->table->nbr_philos == 1)
	{
		safe_mutex(philo->left_fork, UNLOCK);
		ft_usleep(philo->table->time_to_die);
		print_message("died", philo);
		handle_business(philo->table);
		return ;
	}
	safe_mutex(philo->right_fork, LOCK);
	print_message("has taken a fork", philo);
}

void	ft_drop_forks(t_philo *philo)
{
	if (check_philo_state(philo) == DEAD)
		return ;
	safe_mutex(philo->right_fork, UNLOCK);
	safe_mutex(philo->left_fork, UNLOCK);
}