/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:37:43 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/19 08:26:37 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo **philos, t_args *args)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * args->n_of_philo);
	if (!(*philos))
		return (0);
	i = 0;
	while (i < args->n_of_philo)
	{
		(*philos)[i].args = args;
		(*philos)[i].args->died = 0;
		(*philos)[i].fork = i;
		(*philos)[i].id = i;
		(*philos)[i].num_of_eat = 0;
		(*philos)[i].last_eat = get_curr_time();
		(*philos)[i].end = 0;
		i++;
	}
	return (1);
}
