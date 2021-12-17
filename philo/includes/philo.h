/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:47:41 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/17 17:32:34 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>

typedef struct s_args
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_of_eat;
	int				*philos_meals;
	int				philo_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meals_lock;
}					t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_args			*args;
	struct timeval	base_time;
	struct timeval	last_meal;
}					t_philo;

//init
int		init(int argc, char **argv, t_args *args);
int		create_forks(t_args *args);
int		create_philos(t_philo *philos, t_args *args);
int		join_philos(t_philo *philos, t_args *args);

//utils
void	*ft_calloc(unsigned int i);
int		ft_isdigit(int c);
int		ft_arenumbers(char **str);
int		ft_atoi(const char *str);

//dining
void	*dining(void *philo);

//death_check
void	*death_check(void *philo);

//helper
int		time_diff(struct timeval base_time);
void	ft_usleep(int milisec, int *death);
int		last_phil(t_philo *philo);
void	all_meals(t_philo *philo);
void	destroy(t_philo *philos, t_args *args);

//timestamp
void	taking_fork(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	dying(t_philo *philo);

#endif