/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:04:14 by pweinsto          #+#    #+#             */
/*   Updated: 2021/12/03 18:27:36 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void	*roll_dice()
{
	int	*res;

	res = malloc(sizeof(int));
	*res = (rand() % 6) + 1;
	return ((void *)res);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	pthread_t	th;
	int	*res;
	
	pthread_create(&th, NULL, &roll_dice, NULL);
	pthread_join(th, (void **)&res);
	printf("res: %d\n", *res);
	free(res);
	return (1);
}