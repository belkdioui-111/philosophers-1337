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
    philo->args->died = 1;
    printf("%d",philo->i);
	return (0);
}

void	create_philo(t_args *args)
{
	t_philo *arr_philo;
    int     i;
    
    args->died = 0;
    i = 0;  
    arr_philo = malloc(sizeof(t_philo) * args->n_of_philo);
    pthread_mutex_init(&arr_philo->fork, NULL);
    while(i < args->n_of_philo)
    {
        arr_philo[i].args = args;
        pthread_create(&arr_philo[i].thread, NULL, action, &arr_philo[i]);
        // while(arr_philo[i].args->died == 1)
        // {
        //     break;
        // }
        arr_philo[i].i = i;
        i++;
        usleep(10);
    }
}