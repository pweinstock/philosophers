/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:32:18 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/03 16:38:53 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int	mail = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	int	i = 0;
	while (i < 10000)
	{
		pthread_mutex_lock(&mutex);
		mail++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	th[10];
	int	i = 0;
	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex, NULL);
	while (i < 10)
	{
		pthread_create(&th[i], NULL, &routine, NULL);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mail);
	return (1);
}