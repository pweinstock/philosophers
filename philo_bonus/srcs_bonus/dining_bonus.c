/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:41:23 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 17:33:39 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

void	*dining_bonus(t_philo_b *phil)
{
	pthread_t	death;

	sem_wait(phil->args->wait);
	gettimeofday(&phil->base_time, NULL);
	phil->last_meal = phil->base_time;
	pthread_create(&death, NULL, &death_check_bonus, phil);
	if (phil->id % 2 == 0)
		ft_usleep(phil->args->time_to_eat / 2, &phil->args->philo_died);
	while (!phil->args->philo_died)
	{
		sem_wait(phil->args->forks);
		taking_fork_bonus(phil);
		sem_wait(phil->args->forks);
		taking_fork_bonus(phil);
		eating_bonus(phil);
		sleeping_bonus(phil);
		thinking_bonus(phil);
	}
	return (NULL);
}
