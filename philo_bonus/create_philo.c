/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/25 16:12:43 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker_eat(void *ptr)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	i = 0;
	while (i < philos->args->n_of_philo)
	{
		sem_wait(philos->args->sem_eat);
		i++;
	}
	i = 0;
	while (i < philos->args->n_of_philo)
	{
		kill(philos->args->pid[i], SIGKILL);
		i++;
	}
	return (0);
}

void	wait_sem_eat(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->args->n_of_philo)
	{
		sem_wait(philos->args->sem_eat);
		i++;
	}
}

void	create_philo(t_philo *philos)
{
	int			i;
	pthread_t	check_eat;

	philos->args->f_time = get_curr_time();
	wait_sem_eat(philos);
	i = 0;
	while (i < philos->args->n_of_philo)
	{
		philos->args->pid[i] = fork();
		if (philos->args->pid[i] == -1)
			exit(0);
		else if (philos->args->pid[i] == 0)
			action(&philos[i]);
		i++;
	}
	if (philos->args->must_eat > 0)
		pthread_create(&check_eat, 0, checker_eat, philos);
	waitpid(-1, 0, 0);
	i = 0;
	while (i < philos->args->n_of_philo)
	{
		kill(philos->args->pid[i], SIGKILL);
		sem_post(philos->args->sem_eat);
		i++;
	}
}
