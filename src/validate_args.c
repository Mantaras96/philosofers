/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:39:38 by amantara          #+#    #+#             */
/*   Updated: 2022/05/10 20:49:23 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_isalnum(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


int validate_args(int argc, char **argv)
{
	int i;
	
	i = 1;
	while(i < argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (!ft_isalnum(argv[i][j]))
				return (0);
			j++;
		}
		i++;	
	}
}