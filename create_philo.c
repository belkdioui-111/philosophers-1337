/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:05:15 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/04/30 20:13:11 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"


// typedef struct badre_mutex_t
// {
// 	int lock;
// }

// void	badre_mutex_init(badre_mutex_t *t)
// {
// 	t->lock = 0;
// }

// void	badre_mutex_lock(badre_mutex_t *t)
// {
// 	while (t->lock != 0);
// 	t->lock = 1;
// }

// void	badre_mutex_unlock(badre_mutex_t *t)
// {
// 	while (t->lock);
// 	t->lock = 1;
// }

void	*action(void *data)
{
	t_philo *philo;

	philo = (t_philo *) data;
    printf("%d",philo->i);
    printf("time%lld\n",get_curr_time());
	return (0);
}

int	create_philo_and_threads(t_philo *philos)
{
    int     i;
    
    i = 0;
    philos->args->f_time = get_curr_time();
    while(i < philos->args->n_of_philo)
    {
        if(pthread_create(&philos[i].thread, NULL, action, &philos[i]) != 0)
            return (0);
        philos[i].i = i;
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