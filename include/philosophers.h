/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:54:47 by amantara          #+#    #+#             */
/*   Updated: 2022/05/21 10:48:32 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include	<time.h>
# include	<pthread.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<sys/time.h>



typedef struct s_philosophers
{
	pthread_t		threat;
	int				id;
	int				times_eat;
	int				alive;
	int				f_left;
	int				f_right;	
	time_t			last_eat;
	int				waiting_fork;
	struct s_rules	*rules;
}				t_philosophers;

typedef struct s_rules
{
	int						count_philo;
	int						time_to_eat;
	int						time_to_die;
	int						time_to_sleep;
	int						number_eats;
	int						philo_full;
	pthread_mutex_t			*forks;
	pthread_mutex_t			messages_console;
	time_t					time_start;
	struct s_philosophers	*philosophers;
}				t_rules;

//Validate args (validate_args.c)
int			validate_args(int argc, char **argv);
int			ft_isdigit(int c);
//Init struct (init_objs.c)
void		init_args(int argc, char **argv, t_rules *rules);
void		start_forks(t_rules *rules);
void		start_philo(t_rules *rules);
int			start_philo_thread(t_rules *rules);
//Utils (utils.c)
int			ft_atoi(const char *str1);
//main (main.c)
void	start_forks(t_rules *rules);
void	printforks(t_rules *rules);
//Utils time (utils_time.c)
long		ft_time(void);
void		sleep_time(int time);
// Philo thread actions(philo_thread.c)
void		action_eat(t_philosophers *philosopher);
void		action_sleep(t_philosophers *philosopher);
void		action_think(t_philosophers *philosopher);
void		action_die(t_philosophers *philosopher);
void		check_die_philosopher(t_philosophers *philosopher);
void		*philo_thread_func(void *philovoid);
//Show error and clean objects
void		destroy_forks(t_rules	*rules);
void		destoy_thread(t_rules *rules);

#endif
