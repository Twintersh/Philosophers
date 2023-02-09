/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:10:18 by twinters          #+#    #+#             */
/*   Updated: 2023/02/09 17:39:41 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philosophers
{
	int				id;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
}t_philosophers;

typedef struct s_data
{
	int				nb_philosophers;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				nb_philos_eat;
	pthread_t		*threads;
	t_philosophers	*philo;
}t_data;

// setup.c
void	setup_parameters(char **argv, t_data *data);

// utils.c
int		ft_atoi(const char *str);
int		ft_isnumber(char *str);

#endif