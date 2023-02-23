/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:15:21 by twinters          #+#    #+#             */
/*   Updated: 2023/02/23 15:33:30 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
  
t_bool	check_if_running(t_data *data)
{
	t_bool	value;

	pthread_mutex_lock(&data->death_check_mutex);
	value = data->is_running;
	pthread_mutex_unlock(&data->death_check_mutex);
	return (value);
}

void	set_running_to_false(t_data *data, t_philosophers *philo)
{
	unsigned int time;

	pthread_mutex_lock(&data->death_check_mutex);
	if (philo)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		time = get_time_stamp() - philo->data->time;
		printf("%d %d died\n", time, philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	data->is_running = false;
	pthread_mutex_unlock(&data->death_check_mutex);
}
