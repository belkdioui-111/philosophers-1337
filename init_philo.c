#include "philo.h"

void init_philos(t_philo *philos)
{
    int i;

    i=0;
    while(i < philos->args->n_of_philo)
    {
        philos[i].args = philos->args;
        philos[i].args->died=0;
        philos[i].fork = i;
        philos[i].id = i;
        philos[i].num_of_eat = 0;
        philos[i].last_eat=0;
        i++;
    }
}