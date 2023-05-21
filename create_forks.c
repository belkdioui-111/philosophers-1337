/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:37:57 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/21 09:25:01 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_args *args, t_philo *philos)
{
	int	i;

	i = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * args->n_of_philo);
	if (!args->forks)
		return (2);
	philos->args->mutex_incre = malloc(sizeof(pthread_mutex_t)
			* args->n_of_philo);
	if (!philos->args->mutex_incre)
		return (3);
	pthread_mutex_init(&philos->args->print, NULL);
	pthread_mutex_init(&philos->args->mutex_died, NULL);
	while (i < args->n_of_philo)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL) != 0)
			free_mutexes(args, philos, i);
		if (pthread_mutex_init(&(args->forks[i]), NULL) != 0)
			return (4);
		if (pthread_mutex_init(&(philos->args->mutex_incre[i]), NULL) != 0)
			free_mutexes(args, philos, i);
		if (pthread_mutex_init(&(philos->args->mutex_incre[i]), NULL) != 0)
			return (4);
		i++;
	}
	return (0);
}
