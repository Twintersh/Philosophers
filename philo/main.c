/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:27:57 by twinters          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:24 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	setup_parameters(argv, &data);
	launch_threads(&data);
	free(data.philo);
	free(data.threads);
	return (0);
}

static void	check_args(int argc, char **argv)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	if (argc > 6)
		error += printf("Error: Too many arguments.\n");
	if (argc < 5)
		error += printf("Error: Too few arguments.\n");
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
		{
			error += printf("Error: Arguments must be numbers.\n");
			break ;
		}
		i++;
	}
	if (error)
		exit(1);
}

