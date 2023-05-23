/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:17:23 by twinters          #+#    #+#             */
/*   Updated: 2023/02/23 15:48:43 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	print_action(t_philosophers *philo, char *action)
{
	int	time;

	if (!check_if_running(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	time = get_time_stamp() - philo->data->time;
	printf("%d %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

static t_bool	philo_eat(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_action(philo, "has taken a fork");
	if (!philo->left_fork)
		return (false);
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->death_check_mutex);
	philo->last_meal = get_time_stamp() - philo->data->time;
	pthread_mutex_unlock(&philo->data->death_check_mutex);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->eat_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->fork);
	return (true);
}

static void	philo_sleep(t_philosophers *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

static void	philo_think(t_philosophers *philo)
{
	print_action(philo, "is thinking");
}

void	*philo_routine(void *ptr)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)ptr;
	if (philo->id % 2)
		usleep(5000);
	while (check_if_running(philo->data))
	{
		if (!philo_eat(philo))
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (ptr);
}
