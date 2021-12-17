/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:04:16 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 17:36:35 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

void	taking_fork_bonus(t_philo_b *philo)
{
	sem_wait(philo->args->print_lock);
	if (!philo->args->philo_died)
		printf("%d: philo %d is taking a fork\n", \
		time_diff(philo->base_time), philo->id);
	sem_post(philo->args->print_lock);
	return ;
}

void	eating_bonus(t_philo_b *philo)
{
	sem_wait(philo->args->print_lock);
	if (philo->args->philo_died)
	{
		sem_post(philo->args->print_lock);
		return ;
	}
	printf("%d: philo %d is eating\n", time_diff(philo->base_time), philo->id);
	gettimeofday(&philo->last_meal, NULL);
	sem_post(philo->args->print_lock);
	ft_usleep(philo->args->time_to_eat, &philo->args->philo_died);
	if (philo->args->times_of_eat != -1)
		all_meals_bonus(philo);
	sem_post(philo->args->forks);
	sem_post(philo->args->forks);
	return ;
}

void	sleeping_bonus(t_philo_b *philo)
{
	sem_wait(philo->args->print_lock);
	if (philo->args->philo_died)
	{
		sem_post(philo->args->print_lock);
		return ;
	}
	printf("%d: philo %d is sleeping\n", time_diff(philo->base_time), philo->id);
	sem_post(philo->args->print_lock);
	ft_usleep(philo->args->time_to_sleep, &philo->args->philo_died);
	return ;
}

void	thinking_bonus(t_philo_b *philo)
{
	sem_wait(philo->args->print_lock);
	if (!philo->args->philo_died)
		printf("%d: philo %d is thinking\n", \
		time_diff(philo->base_time), philo->id);
	sem_post(philo->args->print_lock);
	return ;
}

void	dying_bonus(t_philo_b *philo)
{
	sem_wait(philo->args->print_lock);
	printf("%d: philo %d died\n", time_diff(philo->base_time), philo->id);
	kill(0, SIGINT);
	return ;
}
