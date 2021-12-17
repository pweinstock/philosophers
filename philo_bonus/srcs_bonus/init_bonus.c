/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:25:56 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 16:16:50 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

int	init_bonus(int argc, char **argv, t_args_b *args)
{
	if (argc < 5 || argc > 6 || !ft_arenumbers(argv))
		return (0);
	args->number_of_philo = ft_atoi(argv[1]);
	if (args->number_of_philo == 0)
		return (0);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args->times_of_eat = ft_atoi(argv[5]);
		args->philos_meals = 0;
	}
	else
		args->times_of_eat = -1;
	args->philo_died = 0;
	args->print_lock = sem_open("printf_lock", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("printf_lock");
	args->wait = sem_open("wait", O_CREAT | O_EXCL, 0644, 0);
	sem_unlink("wait");
	return (1);
}

int	create_forks_bonus(t_args_b *args)
{
	args->forks = sem_open("forks", O_CREAT | O_EXCL, \
	0644, args->number_of_philo);
	sem_unlink("forks");
	return (1);
}

int	create_philos_bonus(t_args_b *args)
{
	int			i;
	int			id;
	t_philo_b	philo;

	i = 0;
	id = 42;
	while (id != 0 && i < args->number_of_philo)
	{
		id = fork();
		if (id == 0)
		{
			philo.id = i + 1;
			philo.args = args;
			dining_bonus(&philo);
		}
		i++;
	}
	usleep(50);
	i = 0;
	while (i++ < args->number_of_philo)
		sem_post(args->wait);
	while (waitpid(0, NULL, 0) > 0)
		;
	return (1);
}
