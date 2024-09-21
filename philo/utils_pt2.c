/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:47 by mikelitoris       #+#    #+#             */
/*   Updated: 2024/09/21 16:04:28 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(char *str, t_philo *philo)
{
	long	time;

	safe_mutex(&philo->table->write_lock, LOCK);
	time = get_current_time();
	if (check_table_ok(philo->table) == true && \
	check_philo_state(philo) != DEAD)
		printf("%zu %d %s\n", (time - philo->table->start), \
		philo->philo_id, str);
	safe_mutex(&philo->table->write_lock, UNLOCK);
}

void	get_last_meal_time(t_philo *philo)
{
	safe_mutex(&philo->mtx_last_meal_time, LOCK);
	philo->last_meal_time = get_current_time();
	safe_mutex(&philo->mtx_last_meal_time, UNLOCK);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
