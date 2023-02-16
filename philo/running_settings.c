/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:15:21 by twinters          #+#    #+#             */
/*   Updated: 2023/02/15 20:18:06 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	check_if_running(t_data *data)
{
	pthread_mutex_lock(&data->death_check_mutex);
	if (data->is_running == false)
	{
		pthread_mutex_unlock(&data->death_check_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->death_check_mutex);
	return (1);
}

void	set_running_to_false(t_data *data)
{
	pthread_mutex_lock(&data->is_running_mutex);
	data->is_running = false;
	pthread_mutex_lock(&data->is_running_mutex);
}
