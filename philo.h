/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:58:33 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/05/25 16:12:08 by bel-kdio         ###   ########.fr       */
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
	int				ac;
	int				n_of_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				must_eat;
	int				died;
	long long		f_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_died;
	pthread_mutex_t	*mutex_incre;
	pthread_mutex_t	print;
}t_args;

typedef struct s_philo
{
	pthread_t	thread;
	t_args		*args;
	long long	last_eat;
	long int	num_of_eat;
	int			fork;
	int			end;
	int			id;
}	t_philo;

//from libft
int			ft_atoi(const char *str);

// for time "get_curr_time"
long long	get_curr_time(void);
void		ft_usleep(unsigned int msec, t_philo *philo);

//check errors and load data in struct args
int			check_error_and_load_data(int ac, char **av, t_args **args);

//create forks
int			create_forks(t_args *args, t_philo *philos);

//initalisation of philo
int			init_philo(t_philo **philos, t_args *args);

// handling data rice
int			should_stop(t_philo *philo);
int			check_number_of_meals(t_philo *philo);
void		ft_print(t_philo *philo, char *str);
int			has_died(t_philo *philo);
int			has_eaten_enough(t_philo *philo);

// action
void		*action(void *ptr);
int			checker(t_philo *philos, int *i);

//free
void		free_all(int num_free, t_philo *philo, t_args *args);
void		free_mutexes(t_args *args, t_philo *philos, int max_index);

int			create_philo_and_threads(t_philo *philos);

#endif
