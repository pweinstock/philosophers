/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:11:53 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 17:32:28 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	time_diff(struct timeval base_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000)) \
	- ((base_time.tv_sec * 1000) + (base_time.tv_usec / 1000)));
}

void	ft_usleep(int milisec, int *death)
{
	struct timeval	base_time;

	gettimeofday(&base_time, NULL);
	while (time_diff(base_time) < milisec && !*death)
		usleep(500);
	return ;
}

int	last_phil(t_philo *philo)
{
	if (philo->id == philo->args->number_of_philo)
		return (0);
	else
		return (philo->id);
}

void	all_meals(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->args->philo_died)
		return ;
	philo->args->philos_meals[philo->id - 1] += 1;
	while (i < philo->args->number_of_philo)
	{
		if (philo->args->philos_meals[i] < philo->args->times_of_eat)
			return ;
		i++;
	}
	pthread_mutex_lock(&philo->args->print_lock);
	philo->args->philo_died = 1;
	printf("%d: philo %d has finished the last meal\n", \
	time_diff(philo->base_time), philo->id);
	i = 0;
	while (i < philo->args->number_of_philo)
	{
		pthread_mutex_unlock(&philo->args->forks[i]);
		i++;
	}
	pthread_mutex_unlock(&philo->args->print_lock);
	return ;
}

void	destroy(t_philo *philos, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philo)
	{
		pthread_mutex_unlock(&args->forks[i]);
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	pthread_mutex_unlock(&args->print_lock);
	pthread_mutex_destroy(&args->print_lock);
	pthread_mutex_unlock(&args->meals_lock);
	pthread_mutex_destroy(&args->meals_lock);
	if (args->times_of_eat != -1)
		free(args->philos_meals);
	free(args->forks);
	free(philos);
	(void)philos;
	return ;
}
