/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:55 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/22 03:37:33 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mapconf	*so_parsing_map(char ***av)
{
	int	fd;

	fd = open((*av)[1], O_RDONLY);
	if (fd < 0)
	{
		perror(RED "Error" WHT);
		return (NULL);
	}
	return (*av);
}

int	so_argcheck(int ac, char ***av)
{
	int	i;

	if (ac == 1 || !(*av)[1] || (*av)[1][0] == '\0')
	{
		ft_putendl_fd(RED "Error:" WHT " empty file path", 2);
		return (0);
	}
	i = 0;
	while ((*av)[1][i] != '\0')
		++i;
	if (i > 4)
	{
		if (ft_strncmp(&((*av)[1][i - 4]), ".ber", 4))
		{
			ft_putendl_fd(RED "Error:" WHT " need map file in .ber format", 2);
			return (0);
		}
	}
	else
	{
		ft_putendl_fd(RED "Error:" WHT " need map file in .ber format", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_mapconf	*game;

	if (!so_argcheck(argc, &argv))
		exit(1);
	game = so_parsing_map(&argv);
	if (!game)
		exit(1);
	return (0);
}
