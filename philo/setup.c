/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:38:14 by twinters          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:11 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philosophers(t_philosophers *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		philo[i].id = i;
		i++;
	}
}

void	setup_parameters(char **argv, t_data *data)
{
	data->nb_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_philos_eat = ft_atoi(argv[5]);
	data->philo = malloc(sizeof(t_philosophers) * data->nb_philosophers);
	data->threads = malloc(sizeof(pthread_t) * data->nb_philosophers);
	set_philosophers(data->philo, data->nb_philosophers);
}