/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 08:32:38 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/25 16:12:59 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(int num_free, t_philo *philo, t_args *args)
{
	if (num_free == 1)
		free(args);
	else if (num_free == 2)
	{
		free(args);
		free(philo);
	}
	else if (num_free == 3)
	{
		free_sema(args);
		free(args->pid);
		free(args);
		free(philo);
	}
	else if (num_free == 4)
		return ;
}
