/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/03 19:26:02 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void    take_fork(t_philo *philo)
{
    pthread_mutex_lock(&(philo->args->forks[philo->id]));
    pthread_mutex_lock(&(philo->args->forks[philo->id + 1]));
    pthread_mutex_lock(&(philo->args->print));
    printf(" has taken a fork\n");
    pthread_mutex_lock(&(philo->args->print));
    pthread_mutex_unlock(&(philo->args->forks[philo->id]));
    pthread_mutex_unlock(&(philo->args->forks[philo->id + 1]));
}

void	*action(void *data)
{
	t_philo *philo;
	philo = (t_philo *) data;
    while(!philo->args->died)
    {
        printf("%d",philo->id);
        // take_fork(philo);
    }
    return (0);
} 

int	create_philo_and_threads(t_philo *philos)
{
    int     i;
    
    i = 0;
    philos->args->f_time = get_curr_time();
    {
        philos[i].args = philos->args;
        i++;
    }
    i = 0;
    while(i < philos->args->n_of_philo)
    {
        if(pthread_create(&philos[i].thread, NULL, action, &philos[i]) != 0)
            return (0);
        i++;
    }
    i = 0;
    while (i < philos->args->n_of_philo)
    {
        if(pthread_join(philos[i].thread, NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}