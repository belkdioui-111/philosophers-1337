/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:38:06 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/11 09:50:41 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(unsigned int msec, t_philo *philo)
{
	long long	start;

	start = get_curr_time();
	while (1)
	{
		usleep(80);
		if (get_curr_time() - start >= msec || should_stop(philo))
			break ;
	}
}

long long	get_curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
