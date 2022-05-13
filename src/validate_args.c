/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:39:38 by amantara          #+#    #+#             */
/*   Updated: 2022/05/13 15:35:23 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}


int validate_args(int argc, char **argv)
{
	int i;
	int j;

	
	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (!ft_isdigit(argv[i][j])){
				write(1, "Error parametros introducidos no son numericos\n", 47);
				return (1);
			}
			j++;
		}
		i++;	
	}
	return (0);
}