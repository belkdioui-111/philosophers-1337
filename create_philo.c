/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/25 16:10:59 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_and_threads(t_philo *philos)
{
	int	i;

	philos->args->f_time = get_curr_time();
	i = 0;
	while (i < philos->args->n_of_philo)
	{
		pthread_create(&philos[i].thread, NULL, action, &philos[i]);
		i = i + 2;
		usleep(5);
	}
	usleep(80);
	i = 1;
	while (i < philos->args->n_of_philo)
	{
		pthread_create(&philos[i].thread, NULL, action, &philos[i]);
		i = i + 2;
		usleep(5);
	}
	i = 0;
	while (i < philos->args->n_of_philo)
	{
		if (!checker(philos, &i))
			return (0);
	}
	return (1);
}
