/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:21:12 by amantara          #+#    #+#             */
/*   Updated: 2022/05/21 14:15:13 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// printf("Philo Fork l:%d Fork r:%d\n", 
// philosophers.f_left, philosophers.f_right);
void	printforks(t_rules *rules)
{
	int				i;
	t_philosophers	philosophers;

	i = 0;
	while (i < rules->count_philo)
	{
		philosophers = rules->philosophers[i];
		printf("Time: %ld\n", rules->time_start);
		i++;
	}
}

//TODO: Agregar funcionalidad para saber si han comido las veces necesarias. 
int	finish_simulation(t_rules *rules)
{
	int				i;

	i = 0;
	while (i < rules->count_philo)
	{
		if (ft_time() - rules->philosophers[i].last_eat > rules->time_to_die)
		{
			rules->philosophers[i].alive = 0;
			action_die(&rules->philosophers[i]);
			return (0);
		}
		i++;
		if (rules->philo_full == rules->count_philo)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
	{
		write(1, "Numero incorrecto de parametros\n", 32);
		return (0);
	}	
	if (validate_args(argc, argv))
		return (0);
	init_args(argc, argv, &rules);
	start_forks(&rules);
	start_philo(&rules);
	start_philo_thread(&rules);
	while (finish_simulation(&rules))
	{
	}
	destroy_forks(&rules);
	destoy_thread(&rules);
	return (0);
}
