/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:41:23 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/11 19:57:33 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*dining(void *philo)
{
	t_philo	*phil;

	phil = (t_philo *)philo;
	gettimeofday(&phil->base_time, NULL);
	phil->last_meal = phil->base_time;
	if (phil->id % 2 == 0)
		usleep(500);
	while (!phil->args->philo_died)
	{
		pthread_mutex_lock(&phil->args->forks[phil->id - 1]);
		taking_fork(phil);
		pthread_mutex_lock(&phil->args->forks[last_phil(phil)]);
		taking_fork(phil);
		eating(phil);
		sleeping(phil);
		thinking(phil);
	}
	//printf("dead id: %d\n", phil->id);
	//printf("time: %d\n", phil->base_time.tv_usec / 1000);
	return (NULL);
}
