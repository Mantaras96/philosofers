/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:23:13 by amantara          #+#    #+#             */
/*   Updated: 2022/05/20 20:10:21 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	action_eat(t_philosophers *philosopher)
{
	time_t	time;

	time = ft_time() - philosopher->rules->time_start;
	philosopher->last_eat = ft_time();
	pthread_mutex_lock(&(philosopher->rules->messages_console));
	printf("%ld %d, is eating\n", time, philosopher->id);
	pthread_mutex_unlock(&(philosopher->rules->messages_console));
	usleep(philosopher->rules->time_to_eat);
	if (philosopher->times_eat >= 1)
		philosopher->times_eat--;
	else if (philosopher->times_eat == 0)
		philosopher->rules->philo_full++;
}

void	action_sleep(t_philosophers *philosopher)
{
	time_t	time;

	time = ft_time() - philosopher->rules->time_start;
	pthread_mutex_lock(&(philosopher->rules->messages_console));
	printf("%ld %d, is sleeping\n", time, philosopher->id);
	pthread_mutex_unlock(&(philosopher->rules->messages_console));
	usleep(philosopher->rules->time_to_sleep);
}

void	action_think(t_philosophers *philosopher)
{
	time_t	time;

	time = ft_time() - philosopher->rules->time_start;
	pthread_mutex_lock(&(philosopher->rules->messages_console));
	printf("%ld %d, is thinking\n", time, philosopher->id);
	pthread_mutex_unlock(&(philosopher->rules->messages_console));
}

void	action_die(t_philosophers *philosopher)
{
	time_t	time;
	time = ft_time() - philosopher->rules->time_start;
	philosopher->alive =  0;
	pthread_mutex_lock(&(philosopher->rules->messages_console));
	printf("%ld %d, died\n", time, philosopher->id);
	pthread_mutex_unlock(&(philosopher->rules->messages_console));
}

void check_die_philosopher(t_philosophers *philosopher){
	if (ft_time() - philosopher->last_eat > philosopher->rules->time_to_die){
		action_die(philosopher);
	}
}

void	*philo_thread_func(void *philovoid)
{
	t_philosophers	*philosopher;
	time_t			time;

	philosopher = (t_philosophers *)philovoid;
	while (philosopher->alive && (philosopher->times_eat > 0 && philosopher->times_eat == -1))
	{
		printf ("Philo %d Fork l:%d Fork r:%d\n", philosopher->id, philosopher->f_left, philosopher->f_right);
		time = ft_time() - philosopher->rules->time_start;
		pthread_mutex_lock(&(philosopher->rules->forks[philosopher->f_right]));
		pthread_mutex_lock(&(philosopher->rules->messages_console));
		printf("%ld %d, has taking a fork right[%d]\n", time, philosopher->id, philosopher->f_right);
		pthread_mutex_unlock(&(philosopher->rules->messages_console));
		pthread_mutex_lock(&(philosopher->rules->forks[philosopher->f_left]));
		pthread_mutex_lock(&(philosopher->rules->messages_console));
		printf("%ld %d, has taking a fork left[%d]\n", time, philosopher->id, philosopher->f_left);
		pthread_mutex_unlock(&(philosopher->rules->messages_console));
		action_eat(philosopher);
		pthread_mutex_unlock(&(philosopher->rules->forks[philosopher->f_left]));
		pthread_mutex_unlock(&(philosopher->rules->forks[philosopher->f_right]));
		if (philosopher->times_eat != 0)
		{
			action_sleep(philosopher);
			action_think(philosopher);
			check_die_philosopher(philosopher);
		}
	}
	return (0);
}

/*
This function will write all actions will doing philosophers
*/
write_action(t_philosophers *philosopher, char *string)
{
		pthread_mutex_lock(&(philosopher->rules->messages_console));

		pthread_mutex_unlock(&(philosopher->rules->messages_console));
}
