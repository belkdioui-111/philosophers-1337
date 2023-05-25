/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_data_rice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:57:41 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/25 16:11:41 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	should_stop(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->args->mutex_died);
	if (philo->args->died)
		ret = 1;
	pthread_mutex_unlock(&philo->args->mutex_died);
	return (ret);
}

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->args->print);
	if (should_stop(philo) == 0)
	{
		printf("%lld %d %s\n", get_curr_time() - philo->args->f_time,
			philo->id + 1, str);
	}
	pthread_mutex_unlock(&(philo->args->print));
}

int	check_number_of_meals(t_philo *philo)
{
	if (philo->args->must_eat <= 0)
		return (0);
	pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
	if (philo->num_of_eat >= philo->args->must_eat)
		philo->end = 1;
	pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
	return (1);
}

int	has_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
	if (get_curr_time() - philo->last_eat >= philo->args->t_to_die)
	{
		pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
	return (0);
}

int	has_eaten_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
	if (philo->end)
	{
		pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
	return (0);
}
