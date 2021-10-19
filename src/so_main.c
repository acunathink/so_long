/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:55 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/19 18:57:06 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_argcheck(int ac, char ***av)
{
	if (ac == 1)
	{
		
	}
		
}

int	main(int argc, char **argv)
{
	if (!so_argcheck(argc, &argv))
	(void) argc;
	(void) argv;
	return (0);
}