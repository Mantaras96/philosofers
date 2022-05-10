/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:54:47 by amantara          #+#    #+#             */
/*   Updated: 2022/05/10 20:46:09 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include	<time.h>
# include	<pthread.h>

typedef struct	s_philosophers
{
	int			id;
	int			times_eat;
	int			alive;
	pthread_t	f_left;
	pthread_t	f_right;	
	time_t		last_eat;
}				t_philosophers;

typedef struct	s_rules
{
	int         count_philo;
	int			time_to_eat;
	int			time_to_die;
	int			time_to_sleep;
	int			number_eats;
	time_t		time_start;
	struct s_philosophers **philosophers;
}               t_rules;

#endif
