/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:17:09 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/04/12 11:35:45 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

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

void	create_philo(t_args *args)
{
	int number_of_p;
	int i;
	t_philo philo;

	i = -1;
	number_of_p = args->n_of_philo + 1;
	while(i++ < number_of_p)
	{
		philo.philo = i;
		if(pthread_create())
	}
}

int	main(int ac, char **av)
{
	t_args	args;

	if (!check_error_and_load_data(ac, av, &args))
		return (0);
	create_philo(&args);
}
