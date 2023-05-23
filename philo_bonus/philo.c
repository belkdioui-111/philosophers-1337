/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:17:09 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/23 12:46:37 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int ac, char **av)
{
	t_args	*args;
	t_philo	*philos;
	int		i;
	
	i = 0;
	if (!check_error_and_load_data(ac, av, &args))
		return (1);
	if (!init_philo(&philos, args))
	{
		free_all(1, philos, args);
		return (1);
	}
	create_sema(args);
	create_philo(philos);
	sem_wait(philos->args->sem_died);
	while(i < args->n_of_philo)
	{
		kill(args->pid[i], SIGKILL);
		i++;
	}
	return (0);
}
