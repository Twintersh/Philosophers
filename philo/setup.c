/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:38:14 by twinters          #+#    #+#             */
/*   Updated: 2023/02/23 11:42:03 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philosophers(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_philosophers)
	{
		pthread_mutex_init(&data->philos[i].fork, NULL);
		if (i > 0)
			data->philos[i].left_fork = &data->philos[i - 1].fork;
		data->philos[i].fat = false;
		data->philos[i].last_meal = 0;
		data->philos[i].nb_meal = 0;
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		i++;
	}
	printf("%d\n", i);
	if (&data->philos[i - 1] != &data->philos[0])
		data->philos[0].left_fork = &data->philos[i - 1].fork;
	else
		data->philos[0].left_fork = NULL;
}

void	setup_parameters(char **argv, t_data *data)
{
	data->time = get_time_stamp();
	data->is_running = true;
	data->nb_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_philos_eat = ft_atoi(argv[5]);
	data->philos = malloc(sizeof(t_philosophers) * data->nb_philosophers);
	data->threads = malloc(sizeof(pthread_t) * data->nb_philosophers);
	set_philosophers(data);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_check_mutex, NULL);
}
