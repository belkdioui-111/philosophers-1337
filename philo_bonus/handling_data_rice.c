/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_data_rice.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:57:41 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/21 18:15:33 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	should_stop(t_philo *philo)
{
	int	ret;

	ret = 0;
	if (philo->args->died)
		ret = 1;
	return (ret);
}

int	ft_print(t_philo *philo, char *str)
{
	if (should_stop(philo) == 0)
	{
		printf("%lld %d %s\n", get_curr_time() - philo->args->f_time,
			philo->id + 1, str);
		return (0);
	}
	else
	{
		return (1);
	}
	
}

int	check_number_of_meals(t_philo *philo)
{
	if (philo->args->must_eat <= 0)
		return (0);
	if (philo->num_of_eat >= philo->args->must_eat)
		philo->end = 1;
	return (1);
}

int	has_died(t_philo *philo)
{
	if (get_curr_time() - philo->last_eat >= philo->args->t_to_die)
	{
		sem_post(philo->args->sem_died);
		return (1);
	}
	return (0);
}

int	has_eaten_enough(t_philo *philo)
{
	if (philo->end)
	{
		return (1);
	}
	return (0);
}
