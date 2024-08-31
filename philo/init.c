#include "philo.h"

void	ft_init(t_sim *table)
{
	safe_mutex(&table->write_lock, INIT);
	safe_mutex(&table->mtx_end_sim, INIT);
	safe_mutex(&table->mtx_full, INIT);
	table->end_sim = false;
	table->threads = malloc(sizeof(pthread_t) * table->nbr_philos);
	if (table->threads == NULL)
		exit(EXIT_FAILURE); //!Check if this is the right way or i should just return NULL
	table->philos = malloc(sizeof(t_philo) * table->nbr_philos);
	if (table->philos == NULL)
		exit(EXIT_FAILURE); //!Check if this is the right way or i should just return NULL
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philos);
	if (table->forks == NULL)
		exit(EXIT_FAILURE); //!Check if this is the right way or i should just return NULL
	ft_init_philos(table);
	ft_init_forks(table);
	//table->start = get_current_time(); //? IT'S INITIALIZED IN threads.c->ft_create_threads --- More acurate timestamp
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

// Just the mtx_philo_state is initialized. Check the other ones and if it's necessary to have them all.
// Last_meal_time is not initialized. Check if i need both this and its mutex.
// Check if we need the full variable. We will have a monitor for that and for the kills.

void	ft_init_philos(t_sim *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philos)
	{
		table->philos[i].table = table;
		table->philos[i].philo_id = (int)(i + 1);
		table->philos[i].meal_counter = 0;
		table->philos[i].state = IDLE;
		safe_mutex(&(table->philos[i].mtx_philo_state), INIT);
		safe_mutex(&(table->philos[i].mtx_last_meal_time), INIT);
		safe_mutex(&(table->philos[i].mtx_meal_counter), INIT);
		//table->philos[i].last_meal_time = get_current_time(); //!Check if i need this or just initialize it with 0.
		i++;
	}
}
