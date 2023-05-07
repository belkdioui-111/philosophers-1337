/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:37:57 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/07 14:49:39 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_forks(t_args *args, t_philo *philos)
{
    int i;

    i = 0;
    args->forks = malloc(sizeof(pthread_mutex_t) * args->n_of_philo);
    if(!args->forks)
        return (0);
    philos->args->mutex_incre = malloc(sizeof(pthread_mutex_t) * args->n_of_philo);
    if(!philos->args->mutex_incre)
        return (0);
    pthread_mutex_init(&philos->args->print, NULL);
    pthread_mutex_init(&philos->args->mutex_died, NULL);
    while (i < args->n_of_philo)
    {
        if (pthread_mutex_init(&(args->forks[i]), NULL) != 0)
            return (0);
        if (pthread_mutex_init(&(philos->args->mutex_incre[i]), NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}
