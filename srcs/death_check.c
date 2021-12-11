/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:08:36 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/11 20:09:16 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*death_check(void *philo)
{
	t_philo	*philos;
	int		i;

	philos = *(t_philo **)philo;
	i = 0;
	while (philos[i].args->philo_died == 0)
	{
		if (time_diff(philos[i].last_meal) >= philos[i].args->time_to_die)
		{
			philos[i].args->philo_died = 1;
			dying(&(philos[i]));
			return (NULL);
		}
		i++;
		if (i >= philos[0].args->number_of_philo)
			i = 0;
	}
	return (NULL);
}
