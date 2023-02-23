/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:37:14 by twinters          #+#    #+#             */
/*   Updated: 2023/02/23 16:05:19 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// trouver le bon check pour verifier si le philo est vivant

static unsigned int	get_last_meal(t_philosophers *philo)
{
	unsigned int	value;

	pthread_mutex_lock(&philo->data->death_check_mutex);
	value = philo->last_meal;
	pthread_mutex_unlock(&philo->data->death_check_mutex);
	return (value);
}

static unsigned int	get_nb_meal(t_philosophers *philo)
{
	unsigned int	value;

	pthread_mutex_lock(&philo->data->death_check_mutex);
	value = philo->nb_meal;
	pthread_mutex_unlock(&philo->data->death_check_mutex);
	return (value);
}

static t_bool	is_philo_dead(t_philosophers *philo, unsigned int time)
{
	if (get_time_stamp() - time - get_last_meal(philo)
		> philo->data->time_to_die)
		return (true);
	return (false);
}

static t_bool	is_philo_fat(t_philosophers *philo, unsigned int nb_philos_eat)
{
	static unsigned int	nb_fat_philos = 0;

	if (!philo->fat && nb_philos_eat && get_nb_meal(philo) >= nb_philos_eat)
	{
		nb_fat_philos++;
		philo->fat = true;
	}
	if (nb_fat_philos >= philo->data->nb_philosophers)
		return (true);
	return (false);
}

void	*checker_philos_alive(void *ptr)
{
	t_data	*data;
	
	int		i;
	int		nb_philo;

	data = (t_data *)ptr;
	nb_philo = data->nb_philosophers;
	i = 0;
	while (1)
	{
		if (is_philo_dead(&data->philos[i % nb_philo], data->time))
		{
			set_running_to_false(data, &data->philos[i % nb_philo]);
			break ;
		}
		if (data->nb_philos_eat
			&& is_philo_fat(&data->philos[i % nb_philo], data->nb_philos_eat))
		{
			set_running_to_false(data, NULL);
			break ;
		}
		usleep(100);
		i++;
	}
	return (NULL);
}
