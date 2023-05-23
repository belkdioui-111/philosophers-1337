/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/23 20:24:12 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_philo *philos)
{
	int	i;

	i = 0;
	philos->args->f_time = get_curr_time();
	
	while (i < philos->args->n_of_philo)
	{
		philos->args->pid[i] = fork();
		if (philos->args->pid[i] == -1)
			return (-1);
		else if (philos->args->pid[i] == 0)
			action(&philos[i]);
		i++;
	}
	waitpid(-1, 0, 0);
	i = 0;
	while(i < philos->args->n_of_philo)
	{
		kill(philos->args->pid[i], SIGKILL);
		i++;
	}
	return (0);
}
