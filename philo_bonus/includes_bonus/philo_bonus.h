/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:41:28 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 16:05:09 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "../../philo/includes/philo.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_args_b
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_of_eat;
	int				philos_meals;
	int				philo_died;
	struct timeval	base_time;
	sem_t			*wait;
	sem_t			*forks;
	sem_t			*print_lock;
}			t_args_b;

typedef struct s_philo_b
{
	int				id;
	t_args_b		*args;
	struct timeval	base_time;
	struct timeval	last_meal;
}					t_philo_b;

//dining
void	*dining_bonus(t_philo_b *phil);

//init
int		init_bonus(int argc, char **argv, t_args_b *args);
int		create_forks_bonus(t_args_b *args);
int		create_philos_bonus(t_args_b *args);

//helper
void	all_meals_bonus(t_philo_b *philo);

//timestamp
void	taking_fork_bonus(t_philo_b *philo);
void	eating_bonus(t_philo_b *philo);
void	sleeping_bonus(t_philo_b *philo);
void	thinking_bonus(t_philo_b *philo);
void	dying_bonus(t_philo_b *philo);

//death
void	*death_check_bonus(void *phil);

//itoa
char	*ft_itoa(int n);

#endif
