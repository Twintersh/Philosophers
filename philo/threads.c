/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:39:38 by twinters          #+#    #+#             */
/*   Updated: 2023/02/21 11:49:55 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	wait_threads(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philosophers)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
}

void	launch_threads(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philosophers)
	{
		pthread_create(&data->threads[i],
			NULL, philo_routine, &data->philos[i]);
		i++;
	}
}
