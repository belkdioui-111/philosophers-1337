/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:37:43 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/11 09:57:06 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philos, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n_of_philo)
	{
		philos[i].args = args;
		philos[i].args->died = 0;
		philos[i].fork = i;
		philos[i].id = i;
		philos[i].num_of_eat = 0;
		philos[i].last_eat = get_curr_time();
		philos[i].end = 0;
		i++;
	}
}
