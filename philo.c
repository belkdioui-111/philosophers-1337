/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:17:09 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/04/14 22:30:47 by bel-kdio         ###   ########.fr       */
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

int	loading_data(char **av, int ac, t_args *args)
{
	args->n_of_philo = ft_atoi(av[1]);
	if (args->n_of_philo <= 0)
		return (0);
	args->t_to_die = ft_atoi(av[2]) * 1000;
	if (args->t_to_die < 0)
		return (0);
	args->t_to_eat = ft_atoi(av[3]) * 1000;
	if (args->t_to_eat < 0)
		return (0);
	args->t_to_sleep = ft_atoi(av[4]) * 1000;
	if (args->t_to_sleep < 0)
		return (0);
	if (ac == 6)
	{
		args->must_eat = ft_atoi(av[5]);
		if (args->must_eat <= 0)
			return (0);
	}
	return (1);
}

int	check_error_and_load_data(int ac, char **av, t_args *args)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error");
		return (0);
	}
	if (!loading_data(av, ac, args))
	{
		printf("Error");
		return (0);
	}
	return (1);
}

void	*action(void *data)
{
	t_philo *philo;

	philo = (t_philo *) data;

	// philo.id
	// philo.last_eat
	// philo.num_eat
	
	// philo.data *
	printf("%d\n",philo->id);

	return (0);
}

void	create_philo(t_args *args)
{
	int		number_of_p;
	int 	id;
	t_philo *head;
	t_philo *node;
	t_philo *tmp;

	id = 0;
	head = NULL;
	number_of_p = args->n_of_philo;
	while(id < number_of_p)
	{
		node = malloc(sizeof(t_philo));
		node->id = id;
		node->next = NULL;
		if (head == NULL){
			head = node;
			tmp = node;
		}
		else
		{
			tmp->next = node;
			tmp = node;
		}
		id++;
	}
	tmp->next = head;
	while(head)
	{
		printf("%d",head->id);
		head=head->next;
	}
}

int	main(int ac, char **av)
{
	t_args	args;

	if (!check_error_and_load_data(ac, av, &args))
		return (0);
	create_philo(&args);
	return 0;
}
