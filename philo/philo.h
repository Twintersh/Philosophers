/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:10:18 by twinters          #+#    #+#             */
/*   Updated: 2023/02/23 11:41:20 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum bool
{
	false = 0,
	true = 1
}t_bool;

typedef struct s_philosophers
{
	int				id;
	t_bool			fat;
	unsigned int	last_meal;
	unsigned int	nb_meal;
	struct s_data	*data;
	pthread_mutex_t	fork;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*left_fork;
}t_philosophers;

typedef struct s_data
{
	t_bool			is_running;
	pthread_t		*threads;
	unsigned int	nb_philosophers;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_die;
	unsigned int	time;
	unsigned int	nb_philos_eat;
	t_philosophers	*philos;
	pthread_mutex_t	death_check_mutex;
	pthread_mutex_t	print_mutex;
}t_data;

// setup.c
void			setup_parameters(char **argv, t_data *data);

// utils.c
unsigned int	ft_atoi(const char *str);
int				ft_isnumber(char *str);
unsigned int	get_time_stamp(void);

// actions.c
void			print_action(t_philosophers *philo, char *action);
void			*philo_routine(void *ptr);

// threads.c
void			wait_threads(t_data *data);
void			launch_threads(t_data *data);

// check_if_running.c
enum bool		check_if_running(t_data *data);
void			set_running_to_false(t_data *data, t_philosophers *philo);

// checker.c
void			*checker_philos_alive(void *ptr);

#endif
