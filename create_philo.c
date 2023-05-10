/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/10 13:05:13 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int should_stop(t_philo *philo)
{
    int ret;

    ret = 0;
    pthread_mutex_lock(&philo->args->mutex_died);
    if (philo->args->died)
        ret = 1;
    pthread_mutex_unlock(&philo->args->mutex_died);
    return (ret);
}

void ft_print(t_philo *philo, char *str)
{
    if (should_stop(philo) == 0)
    {
        pthread_mutex_lock(&philo->args->print);
        printf("%lld %d %s\n", get_curr_time() - philo->args->f_time, philo->id + 1, str);
        pthread_mutex_unlock(&(philo->args->print));
    }
}

void ft_sleep(t_philo *philo)
{
    ft_print(philo, "is sleeping");
    ft_usleep(philo->args->t_to_sleep);
}
void eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
    philo->last_eat = get_curr_time();
    pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
    ft_print(philo, "is eating");
    ft_usleep(philo->args->t_to_eat);
    pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
    philo->num_of_eat++;
    pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
}

void *action(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *)ptr;
    while(should_stop(philo) == 0)
    {
        ft_print(philo, "is thinking");
        pthread_mutex_lock(&(philo->args->forks[philo->id]));
        ft_print(philo, "has taken a fork");
        pthread_mutex_lock(&(philo->args->forks[(philo->id + 1) % philo->args->n_of_philo]));
        ft_print(philo, "has taken a fork");
        eat(philo);
        pthread_mutex_unlock(&(philo->args->forks[philo->id]));
        pthread_mutex_unlock(&(philo->args->forks[(philo->id + 1) % philo->args->n_of_philo]));
        ft_sleep(philo);
        if(philo->num_of_eat >= philo->args->must_eat && philo->args->must_eat > 0)
        {
            philo->end = 1;
            break;
        }
    }
    return (0);
}

int has_died(t_philo *philo)
{
    pthread_mutex_lock(&philo->args->mutex_incre[philo->id]);
    if(get_curr_time() - philo->last_eat >= philo->args->t_to_die)
    {
        pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
        return(1);
    }
    pthread_mutex_unlock(&philo->args->mutex_incre[philo->id]);
    return (0);
}

int create_philo_and_threads(t_philo *philos)
{
    int i;
    int j;
    
    j=0;
    philos->args->f_time = get_curr_time();
    i = 0;
    while (i < philos->args->n_of_philo)
    {
        if (pthread_create(&philos[i].thread, NULL, action, &philos[i]))
            return (0);
        i = i + 2;
        usleep(5);
    }
    usleep(80);
    i = 1;
    while (i < philos->args->n_of_philo)
    {
        if (pthread_create(&philos[i].thread, NULL, action, &philos[i]))
            return (0);
        i = i + 2;
        usleep(5);
    }
    i = 0;    
    while (i < philos->args->n_of_philo)
    {
        if(philos[i].end)
            j++;
        if(j == philos[i].args->n_of_philo)
            break;
        pthread_mutex_lock(&philos[i].args->mutex_died);
        if(has_died(&philos[i]))
        {
            philos[i].args->died = 1;
            pthread_mutex_lock(&philos[i].args->print);
            printf("%lld %d %s\n", get_curr_time() - philos[i].args->f_time, philos[i].id + 1, "died");
            pthread_mutex_unlock(&philos[i].args->mutex_died);
            break;
        }
        pthread_mutex_unlock(&philos[i].args->mutex_died);
        i++;
        if(philos->args->n_of_philo == i)
            i = 0;
    }
    return (1);
}