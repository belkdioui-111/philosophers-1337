/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:17:09 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/04/30 15:34:45 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_philo *philos;

	if (!check_error_and_load_data(ac, av, &args))
		return (0);
	philos = malloc(sizeof(t_philo) * args.n_of_philo);
	philos->args = &args;
	if(!create_forks(philos))
		return (0);
	if(!create_philo_and_threads(philos))
		return (0);
	return 0;
}
