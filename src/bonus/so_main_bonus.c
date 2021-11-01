/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:55 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/01 15:21:54 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_print_map(t_mapconf *mc)
{
	size_t	i;

	i = 0;
	ft_putendl_fd(RED " - - - - - - " WHT, 1);
	while (i < mc->row)
		ft_putstr_fd(mc->map[i++], 1);
}

void	so_map_check_p2(t_mapconf *gm)
{
	gm->wid = 0;
	if (gm->row < 2)
		exit(so_end_with_error("unknown map format"));
	while (gm->wid < gm->col - 1)
		if (gm->map[gm->hei][gm->wid++] != '1')
			exit(so_end_with_error("map must be surrounded by walls"));
	if (gm->exit == 0)
		exit(so_end_with_error("map must have at least one exit"));
	if (gm->colect == 0)
		exit(so_end_with_error("map must have at least one collectible"));
	if (gm->player == 0)
		exit(so_end_with_error("map must have at least one starting position"));
}

void	so_player_check(t_mapconf *gm)
{
	gm->x = gm->wid;
	gm->y = gm->hei;
	if (++gm->player > 1)
		exit(so_end_with_error("map must have only one starting position"));
}

void	so_map_check(t_mapconf *gm)
{
	while (gm->wid < gm->col - 1)
		if (gm->map[0][gm->wid++] != '1')
			exit(so_end_with_error("map must be surrounded by walls"));
	while (++gm->hei < gm->row - 1)
	{
		if (gm->map[gm->hei][0] != '1' || gm->map[gm->hei][gm->col - 2] != '1')
			exit(so_end_with_error("map must be surrounded by walls"));
		gm->wid = 0;
		while (++gm->wid < gm->col - 2)
		{
			if (gm->map[gm->hei][gm->wid] == 'C')
				gm->colect++;
			else if (gm->map[gm->hei][gm->wid] == 'E')
				gm->exit++;
			else if (gm->map[gm->hei][gm->wid] == 'P')
				so_player_check(gm);
			else if (gm->map[gm->hei][gm->wid] != '1' && \
					gm->map[gm->hei][gm->wid] != '0')
				exit(so_end_with_error("unknown map format"));
		}
	}
	so_map_check_p2(gm);
}

int	main(int argc, char **argv)
{
	t_mapconf	game;

	so_arg_check(argc, &argv);
	so_parsing_map(&argv, &game);
	so_map_check(&game);
	so_long(&game);
	exit (0);
}
