/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:54:47 by amantara          #+#    #+#             */
/*   Updated: 2022/05/13 16:22:31 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include	<time.h>
# include	<pthread.h>
# include	<unistd.h>
# include	<stdlib.h>

typedef struct	s_philosophers
{
	int			id;
	int			times_eat;
	int			alive;
	int			f_left;
	int			f_right;	
	time_t		last_eat;
	struct s_rules *rules;
}				t_philosophers;

typedef struct	s_rules
{
	int         count_philo;
	int			time_to_eat;
	int			time_to_die;
	int			time_to_sleep;
	int			number_eats;
	pthread_mutex_t	*forks;
	time_t		time_start;
	struct s_philosophers **philosophers;
}               t_rules;

//Validate args (validate_args.c)
int validate_args(int argc, char **argv);
int	ft_isdigit(int c);
//Init struct (init_objs.c)
void initArgs(int argc, char **argv, t_rules *rules);
void startForks(t_rules *rules);
void startPhilo(t_rules *rules);
//Utils (utils.c)
int	ft_atoi(const char *str1);


#endif
