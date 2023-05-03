/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:58:33 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/03 19:09:33 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct args
{
	int	n_of_philo;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	must_eat;
	int	died;
	long long f_time;
	pthread_mutex_t print;
}t_args;

typedef struct s_philo
{
	pthread_t		thread;
	t_args			*args;
	long int		last_eat;
	long int		num_of_eat;
	pthread_mutex_t	*forks;
	int i;
}	t_philo;

int		ft_atoi(const char *str);
int		check_error_and_load_data(int ac, char **av, t_args *args);
int		create_forks(t_philo *philos);
int		create_philo_and_threads(t_philo *philos);
long long	get_curr_time();
long long diff_bet_first_now(long long first, long long now);


#endif
