/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:04:16 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 17:33:33 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->print_lock);
	if (!philo->args->philo_died)
		printf("%d: philo %d is taking a fork\n", \
		time_diff(philo->base_time), philo->id);
	pthread_mutex_unlock(&philo->args->print_lock);
	return ;
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->print_lock);
	if (philo->args->philo_died)
	{
		pthread_mutex_unlock(&philo->args->print_lock);
		return ;
	}
	printf("%d: philo %d is eating\n", time_diff(philo->base_time), philo->id);
	pthread_mutex_unlock(&philo->args->print_lock);
	gettimeofday(&philo->last_meal, NULL);
	ft_usleep(philo->args->time_to_eat, &philo->args->philo_died);
	if (philo->args->times_of_eat != -1)
	{
		pthread_mutex_lock(&philo->args->meals_lock);
		all_meals(philo);
		pthread_mutex_unlock(&philo->args->meals_lock);
	}
	pthread_mutex_unlock(&philo->args->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->args->forks[last_phil(philo)]);
	return ;
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->print_lock);
	if (philo->args->philo_died)
	{
		pthread_mutex_unlock(&philo->args->print_lock);
		return ;
	}
	printf("%d: philo %d is sleeping\n", time_diff(philo->base_time), philo->id);
	pthread_mutex_unlock(&philo->args->print_lock);
	ft_usleep(philo->args->time_to_sleep, &philo->args->philo_died);
	return ;
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->print_lock);
	if (!philo->args->philo_died)
		printf("%d: philo %d is thinking\n", \
		time_diff(philo->base_time), philo->id);
	pthread_mutex_unlock(&philo->args->print_lock);
	return ;
}

void	dying(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->args->print_lock);
	printf("%d: philo %d died\n", time_diff(philo->base_time), philo->id);
	while (i < philo->args->number_of_philo)
	{
		pthread_mutex_unlock(&philo->args->forks[i]);
		i++;
	}
	pthread_mutex_unlock(&philo->args->print_lock);
	return ;
}
