/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:25:56 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/11 19:29:26 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init(int argc, char **argv, t_args *args)
{
	if (argc < 5 || argc > 6 || !ft_arenumbers(argv))
		return (0);
	args->number_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args->times_of_eat = ft_atoi(argv[5]);
		args->philos_meals = ft_calloc(sizeof(int) * args->number_of_philo);
		if (!args->philos_meals)
			return (0);
		pthread_mutex_init(&args->meals_lock, NULL);
	}
	else
		args->times_of_eat = -1;
	args->philo_died = 0;
	pthread_mutex_init(&args->print_lock, NULL);
	return (1);
}

int	create_forks(t_args *args)
{
	int	i;

	args->forks = ft_calloc(sizeof(pthread_mutex_t) * args->number_of_philo);
	if (!args->forks)
		return (0);
	i = 0;
	while (i < args->number_of_philo)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
	return (1);
}

int	create_philos(t_philo *philos, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].args = args;
		pthread_create(&philos[i].thread, NULL, &dining, &philos[i]);
		i++;
	}
	return (1);
}

int	join_philos(t_philo *philos, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	destroy(philos, args);
	return (1);
}
