/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:21:12 by amantara          #+#    #+#             */
/*   Updated: 2022/05/13 19:56:27 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// void printforks(t_rules *rules){
//     int i;
//     t_philosophers philosophers;

//     i = 0;
//     while(i < rules->count_philo){
//         philosophers = rules->philosophers[i];
//         printf("Philo Fork l:%d Fork r:%d", philosophers.f_left, philosophers.f_right);
//         i++;
//     }
// }

int main(int argc, char **argv)
{
	t_rules	rules;
	
	if (argc < 5 || argc > 6 )
    {
        write(1, "Numero incorrecto de parametros\n", 32);
        return (0);
    }	
	if(validate_args(argc, argv)){
        return(0);
    }
    initArgs(argc, argv, &rules);
    startForks(&rules);
    startPhilo(&rules);
    launch_threats(&rules.philosophers);
    //printforks(&rules);
    return (0);
}