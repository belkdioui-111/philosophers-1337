/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/05 19:01:14 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_sleep(t_philo *philo)
{
    printf("%lld %d is sleeping\n",get_curr_time() - philo->args->f_time, philo->id + 1);
    usleep(philo->args->t_to_sleep);
}
void ft_eating(t_philo *philo)
{
    printf("%lld %d is eating\n",get_curr_time() - philo->args->f_time, philo->id + 1);
    usleep(philo->args->t_to_eat);
    philo->num_of_eat++;    
    philo->last_eat = get_curr_time();
}

void *action(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while(1)
    {
        printf("%lld %d is thinking\n", get_curr_time() - philo->args->f_time, philo->id + 1);
        pthread_mutex_lock(&(philo->args->forks[philo->id]));
        printf("%lld %d has taken a fork\n",get_curr_time() - philo->args->f_time, philo->id + 1);
        pthread_mutex_lock(&(philo->args->forks[(philo->id + 1) % philo->args->n_of_philo]));
        printf("%lld %d has taken a fork\n",get_curr_time() - philo->args->f_time, philo->id + 1);
        ft_eating(philo);
        pthread_mutex_unlock(&(philo->args->forks[philo->id]));
        pthread_mutex_unlock(&(philo->args->forks[(philo->id + 1) % philo->args->n_of_philo]));
        ft_sleep(philo);
        if(philo->num_of_eat >= philo->args->must_eat)
        {
            philo->end = 1;
            break;
        }
    }
    return (0);
}

int create_philo_and_threads(t_philo *philos)
{
    int i;
    
    philos->args->f_time = get_curr_time();
    i = 0;
    while (i < philos->args->n_of_philo)
    {
        if (pthread_create(&philos[i].thread, NULL, action, &philos[i]) != 0)
            return (0);
        i = i + 2;
    }
    usleep(500);
    i = 1;
    while (i < philos->args->n_of_philo)
    {
        if (pthread_create(&philos[i].thread, NULL, action, &philos[i]) != 0)
            return (0);
        i = i + 2;
    }
    i = 0;
    int j = 0;
    while (i < philos->args->n_of_philo)
    {
        if(philos[i].end)
        {
            j++;
        }
        if(j == philos[i].args->n_of_philo)
        {
            break;
        }
        if(get_curr_time() - philos[i].last_eat >= philos[i].args->t_to_die)
        {
             printf("%lld %d is died\n", get_curr_time() - philos[i].args->f_time, philos[i].id + 1);
             break;
        }
        i++;
        if(philos->args->n_of_philo == i)
        {
            i = 0;
        }
    }
    return (1);
}