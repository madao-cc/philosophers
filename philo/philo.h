/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:11 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/21 15:51:09 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> /*To use printf()*/
# include <unistd.h> /*To use usleep()*/
# include <stdlib.h> /*To use malloc() and free()*/
# include <stdbool.h> /*To use bools*/
# include <limits.h> /*To use INT_MAX/INT_MIN*/
# include <sys/time.h> /*To use gettimeofday()*/
# include <pthread.h> /*To use threads and mutex*/
# include "./ft_printf/ft_printf.h" /*To use ft_printf()*/

typedef struct s_philo	t_philo;
typedef enum e_code		t_code;
typedef enum e_state	t_state;

typedef enum e_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
}		t_code;

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	FULL,
	IDLE,
}		t_state;

typedef struct s_sim
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		mtx_end_sim;
	pthread_mutex_t		mtx_full;
	pthread_t			*threads;
	pthread_t			mon_full;
	pthread_t			mon_dead;
	unsigned long		time_to_die;
	long				nbr_philos;
	long				time_to_eat;
	long				time_to_sleep;
	long				goal_of_meals;
	long				start;
	bool				end_sim;
	t_philo				*philos;
}		t_sim;

typedef struct s_philo
{
	pthread_mutex_t		mtx_philo_state;
	pthread_mutex_t		mtx_last_meal_time;
	pthread_mutex_t		mtx_meal_counter;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	int					philo_id;
	unsigned long		last_meal_time;
	long				meal_counter;
	t_state				state;
	t_sim				*table;
}		t_philo;

/* philo.c */
int		main(int argc, char **argv);

/* check_arguments.c */
void	ft_check_arguments(t_sim *table, char **argv);
long	ft_atol(char *str);
int		ft_is_space(char c);
int		ft_is_digit(char c);

/* error_handler.c */
void	safe_mutex(pthread_mutex_t *mutex, t_code code);
void	ft_error_exit(char *error);
void	ft_nuke_all(t_sim *table);

/* init.c */
void	ft_init(t_sim *table);
void	ft_init_philos(t_sim *table);
void	ft_init_forks(t_sim *table);
void	ft_assemble_forks(t_sim *table, int i);

/* routine_actions.c */
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_pickup_forks(t_philo *philo);
void	ft_drop_forks(t_philo *philo);

/* threads.c */
int		ft_create_threads(t_sim *table);
int		ft_joint_threads(t_sim *table);
bool	check_table_ok(t_sim *table);
void	*philo_routine(void *pointer);
void	*monitor_dead(void *pointer);
void	*monitor_full(void *pointer);
void	set_table_on_fire(t_sim *table);
void	handle_1(t_philo *philo);

/* utils.c */
int		ft_usleep(size_t milisseconds);
int		check_any_deaths(t_sim *table);
int		check_philo_died(t_philo *philo);
size_t	get_current_time(void);
bool	is_philo_full(t_philo *philo);

/* utils_pt2.c */
void	print_message(char *str, t_philo *philo);
void	get_last_meal_time(t_philo *philo);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

/* thread_utils.c */
t_state	check_philo_state(t_philo *philo);
void	set_philo_state(t_philo *philo, t_state state);
void	handle_business(t_sim *table);

#endif