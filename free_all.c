/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:32:38 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/19 19:47:37 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutexes(t_args *args, t_philo *philos, int max_index)
{
	int	i;

	i = 0;
	while (i < max_index)
	{
		pthread_mutex_destroy(&(args->forks[i]));
		pthread_mutex_destroy(&(philos->args->mutex_incre[i]));
		i++;
	}
	free(args->forks);
	free(philos->args->mutex_incre);
	free_all(2, philos, args);
}

void	free_all(int num_free, t_philo *philo, t_args *args)
{
	if (num_free == 1)
		free(args);
	else if (num_free == 2)
	{
		free(args);
		free(philo);
	}
	else if (num_free == 3)
	{
		free(args);
		free(philo);
		free(args->forks);
	}
	else if (num_free == 4)
		return ;
}
