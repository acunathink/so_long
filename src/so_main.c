/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:55 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/27 17:08:05 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_end_with_error(char *msg)
{
	if (ft_strncmp(msg, "perror", 6))
	{
		ft_putstr_fd(RED "Error\n\t" WHT ": ", 2);
		ft_putendl_fd(msg, 2);
		write(2, "\n", 1);
	}
	else
	{
		perror(RED "Error\n\t" WHT);
		write(2, "\n", 1);
	}
	return (1);
}

void	so_print_map(t_mapconf *mc)
{
	size_t	i;

	i = 0;
	ft_putendl_fd(RED " - - - - - - " WHT, 1);
	while (i < mc->row)
		ft_putstr_fd(mc->map[i++], 1);
}

void	so_items_account(t_mapconf *gm)
{
	while (gm->x < gm->col - 1)
		if (gm->map[0][gm->x++] != '1')
			exit(so_end_with_error("map must be surrounded by walls"));
	while (++gm->y < gm->row - 1)
	{
		if (gm->map[gm->y][0] != '1' || \
			gm->map[gm->y][gm->col - 2] != '1')
			exit(so_end_with_error("map must be surrounded by walls"));
		gm->x = 0;
		while (++gm->x < gm->col - 2)
		{
			if (gm->map[gm->y][gm->x] == 'C')
				gm->colect++;
			else if (gm->map[gm->y][gm->x] == 'P')
			{
				if (++gm->player > 1)
					exit(so_end_with_error("map must have one start point"));
			}
			else if (gm->map[gm->y][gm->x] != '0' && \
					 gm->map[gm->y][gm->x] != '1' && \
					 gm->map[gm->y][gm->x] != 'E')
				 exit(so_end_with_error("unknown map format"));
		}
	}
}

int	main(int argc, char **argv)
{
	t_mapconf	game;

	if (!so_argcheck(argc, &argv))
		exit(1);
	so_parsing_map(&argv, &game);
	so_print_map(&game);
	so_items_account(&game);
	exit (0);
}
