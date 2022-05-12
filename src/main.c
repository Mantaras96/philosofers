/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:21:12 by amantara          #+#    #+#             */
/*   Updated: 2022/05/12 21:13:46 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	t_rules	rules;
	
	if (argc < 4 || argc > 6 )
		return (0);
	if(!validate_args(argc, argv)){
        return(0);
    };
    initArgs(argc, argv, &rules);
    return (0);
}