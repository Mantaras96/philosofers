/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:23:13 by amantara          #+#    #+#             */
/*   Updated: 2022/05/21 14:22:41 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	action_eat(t_philosophers *philosopher)
{
	time_t	time;

	time = ft_time() - philosopher->rules->time_start;
	philosopher->last_eat = ft_time();
	write_action(philosopher, "is eating");
	sleep_time(philosopher->rules->time_to_eat);
	if (philosopher->times_eat >= 1)
		philosopher->times_eat--;
	else if (philosopher->times_eat == 0)
		philosopher->rules->philo_full++;
}

void	action_sleep(t_philosophers *philosopher)
{
	time_t	time;

	time = ft_time() - philosopher->rules->time_start;
	write_action(philosopher, "is sleeping");
	sleep_time(philosopher->rules->time_to_sleep);
}

void	action_think(t_philosophers *philosopher)
{
	time_t	time;

	time = ft_time() - philosopher->rules->time_start;
	write_action(philosopher, "is thinking");
}

void	action_die(t_philosophers *philosopher)
{
	time_t	time;

	time = ft_time() - philosopher->rules->time_start;
	philosopher->alive = 0;
	write_action(philosopher, "died");
}

void	check_die_philosopher(t_philosophers *philosopher)
{
	if (ft_time() - philosopher->last_eat > philosopher->rules->time_to_die)
		action_die(philosopher);
}

void	*philo_thread_func(void *philovoid)
{
	t_philosophers	*philosopher;
	time_t			time;

	philosopher = (t_philosophers *)philovoid;
	while (philosopher->alive && (philosopher->times_eat > 0 && philosopher->times_eat == -1) && philosopher->waiting_fork == 0)
	{
		philosopher->waiting_fork = 1;
		time = ft_time() - philosopher->rules->time_start;
		pthread_mutex_lock(&(philosopher->rules->forks[philosopher->f_right]));
		write_action(philosopher, "has taking a fork right");
		pthread_mutex_lock(&(philosopher->rules->forks[philosopher->f_left]));
		write_action(philosopher, "has taking a fork left");
		action_eat(philosopher);
		pthread_mutex_unlock(&(philosopher->rules->forks[philosopher->f_left]));
		pthread_mutex_unlock(&(philosopher->rules->forks[philosopher->f_right]));
		if (philosopher->times_eat != 0)
		{
			action_sleep(philosopher);
			action_think(philosopher);
			check_die_philosopher(philosopher);
		}
		philosopher->waiting_fork = 0;
	}
	return (0);
}

/*
This function will write all actions will doing philosophers
(Time) (Philo id),(String)
*/

void	write_action(t_philosophers *philosopher, char *string)
{
	pthread_mutex_lock(&(philosopher->rules->messages_console));
	printf("%ld", ft_time() - philosopher->rules->time_start);
	printf("%d,", philosopher->id);
	printf("%s\n", string);
	pthread_mutex_unlock(&(philosopher->rules->messages_console));
}
