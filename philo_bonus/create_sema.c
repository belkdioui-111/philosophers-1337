/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sema.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:55:10 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/23 18:07:25 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_sema(t_args *args)
{
	sem_unlink("forks");
	sem_unlink("died");
	sem_unlink("incre");
	sem_unlink("print");
	args->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, args->n_of_philo);
	args->sem_died = sem_open("died", O_CREAT | O_EXCL, 0644, 1);
	args->sem_incre = sem_open("incre", O_CREAT | O_EXCL, 0644, 1);
	args->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
}
