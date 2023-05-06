/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_and_loading_data.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:03:31 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/06 16:12:07 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_usleep(unsigned int msec)
{
	long long start;

	start = get_curr_time();
	while(1)
	{
		usleep(85);
		if(get_curr_time() - start >= msec)
			break;
	}
}

int	loading_data(char **av, int ac, t_args *args)
{
	args->n_of_philo = ft_atoi(av[1]);
	args->t_to_die = ft_atoi(av[2]);
	args->t_to_eat = ft_atoi(av[3]);
	args->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->must_eat = ft_atoi(av[5]);
	else if(ac < 6)
		args->must_eat = -1;
	if (args->n_of_philo <= 0 || args->t_to_die <= 0 || args->t_to_eat <= 0 || args->t_to_sleep <= 0 || (args->must_eat == 0 || args->must_eat < -1))
		return (0);
	return (1);
}

int	check_error_and_load_data(int ac, char **av, t_args *args)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error\n");
		return (0);
	}
	if (!loading_data(av, ac, args))
	{
		printf("Error\n");
		return (0);
	}
	return (1);
}