/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:55 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/20 17:22:48 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_argcheck(int ac, char ***av)
{
	int	i;
	
	if (ac == 1 || !(*av)[1] || (*av)[1][0] == '\0')
	{
		ft_putendl_fd(RED "Error:" WHT " empty file path", 2);
		return (0);
	i = 0;
	while (av[1][i] != '\0')
		++i;
	
	return (1);
}

int	main(int argc, char **argv)
{
	if (!so_argcheck(argc, &argv))
		(void) argc;
	(void) argv;
	return (0);
}
