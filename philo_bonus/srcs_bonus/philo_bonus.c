/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:40:41 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 15:09:51 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_args_b		args;

	if (!init_bonus(argc, argv, &args))
		return (0);
	if (!create_forks_bonus(&args))
		return (0);
	create_philos_bonus(&args);
	return (0);
}
