/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_and_loading_data.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:03:31 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/04/30 13:06:02 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	loading_data(char **av, int ac, t_args *args)
{
	args->n_of_philo = ft_atoi(av[1]);
	if (args->n_of_philo <= 0)
		return (0);
	args->t_to_die = ft_atoi(av[2]) * 1000;
	if (args->t_to_die < 0)
		return (0);
	args->t_to_eat = ft_atoi(av[3]) * 1000;
	if (args->t_to_eat < 0)
		return (0);
	args->t_to_sleep = ft_atoi(av[4]) * 1000;
	if (args->t_to_sleep < 0)
		return (0);
	if (ac == 6)
	{
		args->must_eat = ft_atoi(av[5]);
		if (args->must_eat <= 0)
			return (0);
	}
	return (1);
}

int	check_error_and_load_data(int ac, char **av, t_args *args)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error");
		return (0);
	}
	if (!loading_data(av, ac, args))
	{
		printf("Error");
		return (0);
	}
	return (1);
}