/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:11:53 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 16:02:33 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

void	all_meals_bonus(t_philo_b *philo)
{
	if (philo->args->philo_died)
		return ;
	philo->args->philos_meals += 1;
	if (philo->args->philos_meals < philo->args->times_of_eat)
		return ;
	sem_post(philo->args->forks);
	sem_post(philo->args->forks);
	sem_wait(philo->args->print_lock);
	printf("%d: philo %d has finished the last meal\n", \
	time_diff(philo->base_time), philo->id);
	sem_post(philo->args->print_lock);
	exit(0);
}
