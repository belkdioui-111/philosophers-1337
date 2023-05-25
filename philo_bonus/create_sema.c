/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sema.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:55:10 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/25 16:12:52 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_sema(t_args *args)
{
	sem_unlink("/forks");
	sem_unlink("/died");
	sem_unlink("/incre");
	sem_unlink("/print");
	sem_unlink("/eat");
	args->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, args->n_of_philo);
	args->sem_died = sem_open("/died", O_CREAT | O_EXCL, 0644, 1);
	args->sem_eat = sem_open("/eat", O_CREAT | O_EXCL, 0644, args->n_of_philo);
	args->sem_incre = sem_open("/incre", O_CREAT | O_EXCL, 0644, 1);
	args->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
}

void	free_sema(t_args *args)
{
	if (sem_close(args->forks))
		printf("err1\n");
	if (sem_close(args->sem_died))
		printf("err1\n");
	if (sem_close(args->sem_incre))
		printf("err1\n");
	if (sem_close(args->print))
		printf("err1\n");
	if (sem_close(args->sem_eat))
		printf("err1\n");
	if (sem_unlink("/forks"))
		printf("err\n");
	if (sem_unlink("/died"))
		printf("err\n");
	if (sem_unlink("/eat"))
		printf("err\n");
	if (sem_unlink("/incre"))
		printf("err\n");
	if (sem_unlink("/print"))
		printf("err\n");
}
