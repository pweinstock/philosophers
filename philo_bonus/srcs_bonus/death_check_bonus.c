/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:08:36 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 16:52:23 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

void	*death_check_bonus(void *phil)
{
	t_philo_b	*philo;

	philo = (t_philo_b *)phil;
	while (philo->args->philo_died == 0)
	{
		if (time_diff(philo->last_meal) >= philo->args->time_to_die)
		{
			philo->args->philo_died = 1;
			dying_bonus(philo);
			return (NULL);
		}
		usleep(philo->args->number_of_philo * 100);
	}
	return (NULL);
}
