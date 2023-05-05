/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:37:57 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/04 22:44:15 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_forks(t_args *args)
{
    int i;

    i = 0;
    args->forks = malloc(sizeof(pthread_mutex_t) * args->n_of_philo);
    if(!args->forks)
        return (0);
    if (pthread_mutex_init(&(args->print), NULL) != 0)
        return (0);
    while (i < args->n_of_philo)
    {
        if (pthread_mutex_init(&(args->forks[i]), NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}
