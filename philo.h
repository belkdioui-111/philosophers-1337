/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:58:33 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/04/14 22:25:39 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

typedef struct args
{
	int	n_of_philo;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	must_eat;
}t_args;

typedef struct s_philo
{
	int 		id;
	pthread_t 	thread;
	t_args 		args;
	long int	last_eat;
	long int	num_of_eat;
	int			*data;
	struct s_philo *next;
}	t_philo;

int	ft_atoi(const char *str);

#endif
