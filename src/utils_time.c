/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:49:58 by amantara          #+#    #+#             */
/*   Updated: 2022/05/20 18:45:01 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
Return time if you divide /100 will get timestamp today. 
*/

long	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (res);
}

/*
Sleep loop because the usleep function aren't exactly.
*/
void	sleep_time(long long time)
{
	long long	time;

	time = get_timestamp();
	while (1)
	{
		if (get_timestamp() - time >= time)
			break ;
		usleep(100);
	}
}