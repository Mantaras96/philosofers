/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:21:12 by amantara          #+#    #+#             */
/*   Updated: 2022/05/13 16:14:12 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	t_rules	rules;
	
	if (argc < 4 || argc > 6 )
    {
        write(1, "Numero incorrecto de parametros\n", 32);
        return (0);
    }	
	if(!validate_args(argc, argv))
        return(0);
    initArgs(argc, argv, &rules);
    startForks(&rules);
    return (0);
}