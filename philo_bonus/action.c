/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:28:53 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/25 16:33:18 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	if (ft_print(philo, "is sleeping"))
		return (1);
	ft_usleep(philo->args->t_to_sleep, philo);
	return (0);
}

int	eat(t_philo *philo)
{
	sem_wait(philo->args->sem_incre);
		philo->last_eat = get_curr_time();
	sem_post(philo->args->sem_incre);
	if (ft_print(philo, "is eating"))
		return (1);
	ft_usleep(philo->args->t_to_eat, philo);
	sem_wait(philo->args->sem_incre);
	philo->num_of_eat++;
	sem_post(philo->args->sem_incre);
	return (0);
}

void	*checker(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
	{
		if (philos->num_of_eat == philos->args->must_eat)
		{
			philos->num_of_eat += 1;
			sem_post(philos->args->sem_eat);
			return (0);
		}
		sem_wait(philos->args->sem_died);
		sem_wait(philos->args->sem_incre);
		if (get_curr_time() - philos->last_eat >= philos->args->t_to_die)
		{	
			sem_wait(philos->args->print);
			printf("%lld %d %s\n", get_curr_time() - philos->args->f_time,
				philos->id + 1, "died");
			sem_post(philos->args->sem_incre);
			exit(1);
		}
		sem_post(philos->args->sem_incre);
		sem_post(philos->args->sem_died);
	}
	exit(1);
}

void	action(t_philo	*philo)
{
	pthread_create(&philo->thread, 0, checker, philo);
	while (1)
	{
		if (ft_print(philo, "is thinking"))
			break ;
		sem_wait(philo->args->forks);
		if (ft_print(philo, "has taken a fork"))
			break ;
		sem_wait(philo->args->forks);
		if (ft_print(philo, "has taken a fork"))
			break ;
		if (eat(philo))
			break ;
		sem_post(philo->args->forks);
		sem_post(philo->args->forks);
		if (ft_sleep(philo))
			break ;
	}
	sem_post(philo->args->forks);
	sem_post(philo->args->forks);
	pthread_join(philo->thread, NULL);
	exit(1);
}
