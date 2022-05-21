/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:38:01 by amantara          #+#    #+#             */
/*   Updated: 2022/05/21 10:41:46 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_args(int argc, char **argv, t_rules *rules)
{
	rules->count_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->number_eats = ft_atoi(argv[5]);
	else
		rules->number_eats = -1;
	rules->time_start = ft_time();
}

void	start_forks(t_rules *rules)
{
	int				nbr_philo;
	pthread_mutex_t	*forks;

	nbr_philo = rules->count_philo - 1;
	forks = malloc(sizeof(pthread_mutex_t) * nbr_philo - 1);
	while (nbr_philo >= 0)
	{
		pthread_mutex_init(&forks[nbr_philo], NULL);
		--nbr_philo;
	}
	pthread_mutex_init(&rules->messages_console, NULL);
	rules->forks = forks;
}

/*
	This function starts our arrray with all philos. 
*/
void	start_philo(t_rules *rules)
{
	int				nbr_philo;
	t_philosophers	*philosophers;

	philosophers = malloc(sizeof(t_philosophers) * (rules->count_philo));
	nbr_philo = 0;
	while (nbr_philo < rules->count_philo)
	{
		philosophers[nbr_philo].id = nbr_philo;
		philosophers[nbr_philo].times_eat = nbr_philo;
		philosophers[nbr_philo].rules = rules;
		philosophers[nbr_philo].alive = 1;
		philosophers[nbr_philo].waiting_fork = 0;
		if (nbr_philo > 0)
		{
			philosophers[nbr_philo].f_left = nbr_philo - 1;
			philosophers[nbr_philo].f_right = nbr_philo;
		}
		else
		{
			philosophers[nbr_philo].f_left = rules->count_philo - 1;
			philosophers[nbr_philo].f_right = nbr_philo;
		}
		nbr_philo++;
	}
	rules->philosophers = philosophers;
}

/*
	This function start diferent philo threads 
*/
int	start_philo_thread(t_rules *rules)
{
	int				nbr_philo;
	t_philosophers	*philo;	

	nbr_philo = 0;
	while (nbr_philo < rules->count_philo)
	{
		philo = &rules->philosophers[nbr_philo];
		philo->last_eat = rules->time_start;
		pthread_create(&(philo->threat), NULL, philo_thread_func, philo);
		nbr_philo++;
	}
	return (0);
}
