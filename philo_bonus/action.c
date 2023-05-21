/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:28:53 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/21 19:16:19 by bel-kdio         ###   ########.fr       */
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
	philo->last_eat = get_curr_time();
	if(ft_print(philo, "is eating"))
		return (1);
	ft_usleep(philo->args->t_to_eat, philo);
	philo->num_of_eat++;
	return (0);
}

void	lock_and_unlock_died(t_philo *philos)
{
	philos->args->died = 1;
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
			lock_and_unlock_died(philos);
			return (0);
		}
		if (has_died(philos))
		{
			lock_and_unlock_died(philos);
			printf("%lld %d %s\n", get_curr_time() - philos->args->f_time,
				philos->id + 1, "died");
			return (0);
		}
	}
	return (0);
}

void	action(t_philo	*philo)
{
	pthread_t thread;
	pthread_create(&thread, 0, checker, philo);
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
		check_number_of_meals(philo);
	}
}
