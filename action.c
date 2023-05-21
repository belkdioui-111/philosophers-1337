/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:28:53 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/21 10:28:32 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	lock_and_unlock_died(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->mutex_died);
	philos->args->died = 1;
	pthread_mutex_unlock(&philos->args->mutex_died);
}

int	checker(t_philo *philos, int *i)
{
	static int	j;

	if (has_eaten_enough(&philos[*i]))
		j++;
	if (j == philos[*i].args->n_of_philo)
	{
		lock_and_unlock_died(philos);
		return (0);
	}
	if (has_died(&philos[*i]))
	{
		lock_and_unlock_died(philos);
		pthread_mutex_lock(&philos[*i].args->print);
		printf("%lld %d %s\n", get_curr_time() - philos[*i].args->f_time,
			philos[*i].id + 1, "died");
		pthread_mutex_unlock(&philos[*i].args->print);
		return (0);
	}
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
		if(philo->args->n_of_philo !=1 )
		{
			pthread_mutex_lock(&(philo->args->forks[(philo->id + 1)
					% philo->args->n_of_philo]));
			ft_print(philo, "has taken a fork");
			eat(philo);
			pthread_mutex_unlock(&(philo->args->forks[(philo->id + 1)
					% philo->args->n_of_philo]));
		}
		else
			break;
		pthread_mutex_unlock(&(philo->args->forks[philo->id]));
		ft_sleep(philo);
		check_number_of_meals(philo);
	}
	return (0);
}
