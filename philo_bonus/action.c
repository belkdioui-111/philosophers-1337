/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:28:53 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/23 20:00:19 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	if(ft_print(philo, "is sleeping"))
		return (1);
	ft_usleep(philo->args->t_to_sleep, philo);
	return (0);
}

int	eat(t_philo *philo)
{
	sem_wait(philo->args->sem_incre);
		philo->last_eat = get_curr_time();
	sem_post(philo->args->sem_incre);
	
	if(ft_print(philo, "is eating"))
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
	int i;
	int j;

	i = 0;
	j = 0;
	philos = (t_philo *)ptr;
	while (1)
	{
		if (has_eaten_enough(philos))
			j++;
		if (j == philos->args->n_of_philo)
		{
			sem_wait(philos->args->print);
			sem_wait(philos->args->sem_incre);
			philos->args->died = 1;
			sem_post(philos->args->sem_incre);
			sem_post(philos->args->sem_died);
			return (0);
		}
		sem_wait(philos->args->sem_died);
		if (get_curr_time() - philos->last_eat >= philos->args->t_to_die)
		{	
			sem_wait(philos->args->print);
			printf("%lld %d %s\n", get_curr_time() - philos->args->f_time,
				philos->id + 1, "died");
			exit(1);
		}
		sem_post(philos->args->sem_died);
	}
	exit(1);
}

void	action(t_philo	*philo)
{
	pthread_create(&philo->thread, 0, checker, philo);
	while (1)
	{
		if(ft_print(philo, "is thinking"))
			break ;
		sem_wait(philo->args->forks);
		if(ft_print(philo, "has taken a fork"))
			break ;
		sem_wait(philo->args->forks);
		if(ft_print(philo, "has taken a fork"))
			break ;
		if(eat(philo))
			break ;
		sem_post(philo->args->forks);
		sem_post(philo->args->forks);
		if(ft_sleep(philo))
			break ;
		// check_number_of_meals(philo);
	}
	exit(1);
	// pthread_join(philo->thread, NULL);
}
