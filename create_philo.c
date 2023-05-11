/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/11 17:39:29 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	leaks
*/

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->args->t_to_sleep, philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
	philo->last_eat = get_curr_time();
	pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
	ft_print(philo, "is eating");
	ft_usleep(philo->args->t_to_eat, philo);
	pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
}

int	checker(t_philo *philos, int *i)
{
	static int	j;

	if (has_eaten_enough(&philos[*i]))
		j++;
	if (j == philos[*i].args->n_of_philo)
	{
		pthread_mutex_lock(&philos->args->mutex_died);
		philos->args->died = 1;
		pthread_mutex_unlock(&philos->args->mutex_died);
		return (0);
	}
	pthread_mutex_lock(&philos[*i].args->mutex_died);
	if (has_died(&philos[*i]))
	{
		philos[*i].args->died = 1;
		pthread_mutex_lock(&philos[*i].args->print);
		printf("%lld %d %s\n", get_curr_time() - philos[*i].args->f_time,
			philos[*i].id + 1, "died");
		pthread_mutex_unlock(&philos[*i].args->mutex_died);
		return (0);
	}
	pthread_mutex_unlock(&philos[*i].args->mutex_died);
	(*i)++;
	if (philos->args->n_of_philo == *i)
		*i = 0;
	return (1);
}

void	*action(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (should_stop(philo) == 0)
	{
		ft_print(philo, "is thinking");
		pthread_mutex_lock(&(philo->args->forks[philo->id]));
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->args->forks[(philo->id + 1)
				% philo->args->n_of_philo]));
		ft_print(philo, "has taken a fork");
		eat(philo);
		pthread_mutex_unlock(&(philo->args->forks[philo->id]));
		pthread_mutex_unlock(&(philo->args->forks[(philo->id + 1)
				% philo->args->n_of_philo]));
		ft_sleep(philo);
		check_number_of_meals(philo);
	}
	return (0);
}

int	create_philo_and_threads(t_philo *philos)
{
	int	i;

	philos->args->f_time = get_curr_time();
	i = 0;
	while (i < philos->args->n_of_philo)
	{
		pthread_create(&philos[i].thread, NULL, action, &philos[i]);
		i = i + 2;
		usleep(5);
	}
	usleep(80);
	i = 1;
	while (i < philos->args->n_of_philo)
	{
		pthread_create(&philos[i].thread, NULL, action, &philos[i]);
		i = i + 2;
		usleep(5);
	}
	i = 0;
	while (i < philos->args->n_of_philo)
	{
		if (!checker(philos, &i))
			return (0);
	}
	return (1);
}
