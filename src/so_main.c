/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:55 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/19 19:59:29 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_argcheck(int ac, char ***av)
{
	if (ac == 1 || !(*av)[1] || (*av)[1][0] == '\0')
	{
		ft_putendl_fd(RED "Error:" WHT " empty file path", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (!so_argcheck(argc, &argv))
		(void) argc;
	(void) argv;
	return (0);
}