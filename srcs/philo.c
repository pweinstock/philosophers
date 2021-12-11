/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:47:08 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/11 19:28:49 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args		args;
	t_philo		*philos;
	pthread_t	death;

	if (!init(argc, argv, &args))
		return (0);
	if (!create_forks(&args))
		return (0);
	philos = ft_calloc(sizeof(t_philo) * args.number_of_philo);
	if (!philos)
		return (0);
	create_philos(philos, &args);
	pthread_create(&death, NULL, &death_check, &philos);
	join_philos(philos, &args);
	pthread_join(death, NULL);
	printf("Game over!\n");
	return (0);
}
