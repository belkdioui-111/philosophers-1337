#include "philo.h"

int create_forks(t_philo *philos)
{
    int i;

    i = 0;
    philos->args->forks = malloc(sizeof(pthread_mutex_t) * philos->args->n_of_philo);
    if(!philos->args->forks)
        return (0);
    if (pthread_mutex_init(&philos->args->print, NULL) != 0)
        return (0);
    while (i < philos->args->n_of_philo)
    {
        if (pthread_mutex_init(&philos->args->forks[i], NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}