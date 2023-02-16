/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:17:23 by twinters          #+#    #+#             */
/*   Updated: 2023/02/16 08:40:24 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	print_action(t_philosophers *philo, char *action)
{
	int	time;

	time = get_time_stamp() - philo->data->time;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (check_if_running(philo->data))
		printf("%d %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

static void	philo_take_fork(t_philosophers *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_action(philo, "has taken a fork");
}

static void	philo_eat(t_philosophers *philo)
{
	philo_take_fork(philo, &philo->fork);
	philo_take_fork(philo, philo->left_fork);
	if (philo->last_meal >= philo->data->time_to_die)
		set_running_to_false(philo->data);
	print_action(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	philo->last_meal = get_time_stamp() - philo->data->time;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->left_fork);
}

static void	philo_sleep(t_philosophers *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->data->time_to_sleep);
}

static void	philo_think(t_philosophers *philo)
{
	print_action(philo, "is thinking");
}

void	*philo_routine(void *ptr)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)ptr;
	if (philo->id % 2 == 1)
		usleep(500);
	while (check_if_running(philo->data))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (ptr);
}
