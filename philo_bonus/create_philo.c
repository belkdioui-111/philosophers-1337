/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/21 18:10:34 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_philo *philos)
{
	int	i;

	i = 0;
	philos->args->f_time = get_curr_time();
	while(i < philos->args->n_of_philo)
	{
		philos->args->pid[i] = fork();
		if (philos->args->pid[i] == -1)
			return (-1);
		else if (philos->args->pid[i] == 0)
			action(&philos[i]);
		else
			i++;
	}
	return(0);
	
}
