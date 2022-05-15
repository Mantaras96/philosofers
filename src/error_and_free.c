/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:40:25 by amantara          #+#    #+#             */
/*   Updated: 2022/05/15 19:31:23 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	show_error_msg(char *str)
{
	printf("%s", str);
}

void	destroy_forks(t_rules *rules)
{
	int	nbr_philo;

	nbr_philo = rules->count_philo - 1;
	while (nbr_philo >= 0)
	{
		pthread_mutex_destroy(&rules->forks[nbr_philo]);
		--nbr_philo;
	}
}

void	destoy_thread(t_rules *rules)
{
	int				nbr_philo;
	t_philosophers	*philosopher;

	nbr_philo = rules->count_philo;
	while (nbr_philo >= 0)
	{
		philosopher = &rules->philosophers[nbr_philo];
		pthread_join(philosopher->threat, NULL);
	}
}
