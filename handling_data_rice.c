/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_data_rice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:57:41 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/11 10:04:46 by bel-kdio         ###   ########.fr       */
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
	if (should_stop(philo) == 0)
	{
		pthread_mutex_lock(&philo->args->print);
		printf("%lld %d %s\n", get_curr_time() - philo->args->f_time,
			philo->id + 1, str);
		pthread_mutex_unlock(&(philo->args->print));
	}
}

int	max_of_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
	if (philo->num_of_eat >= philo->args->must_eat && philo->args->must_eat > 0)
	{
		pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
	return (0);
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
