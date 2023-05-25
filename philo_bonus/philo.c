/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:17:09 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/25 16:13:44 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	main(int ac, char **av)
{
	t_args	*args;
	t_philo	*philos;

	if (!check_error_and_load_data(ac, av, &args))
		return (1);
	if (!init_philo(&philos, args))
	{
		free_all(1, philos, args);
		return (1);
	}
	create_sema(args);
	create_philo(philos);
	free_all(3, philos, args);
	return (0);
}
