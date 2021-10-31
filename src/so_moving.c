/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:57:34 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/31 19:09:10 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_make_move(size_t turn_x, size_t turn_y, t_mapconf *gm)
{
	char	ex;

	if ((gm->map[turn_y][turn_x] != '1' && gm->map[turn_y][turn_x] != 'E') || \
		(gm->map[turn_y][turn_x] == 'E' && !gm->colect))
	{
		if (gm->map[turn_y][turn_x] == 'C')
			--gm->colect;
		ex = gm->map[turn_y][turn_x];
		gm->map[turn_y][turn_x] = 'P';
		gm->map[gm->y][gm->x] = '0';
		mlx_put_image_to_window(gm->mlx, gm->window, gm->img->black, \
								gm->x * gm->img->wid, gm->y * gm->img->hei);
		so_put_image(gm->x, gm->y, gm);
		gm->y = turn_y;
		gm->x = turn_x;
		so_put_image(turn_x, turn_y, gm);
		if (ex == 'E')
			exit (so_close_game(WINNER, gm));
		return (1);
	}
	else
		printf(YELL " (can't move here)\n" WHT);
	return (0);
}

int	so_move_player(int keycode, t_mapconf *gm)
{
	if (keycode == PRESS_ESC)
		exit (so_close_game(keycode, gm));
	else if (keycode == PRESS_W || keycode == UP)
		so_make_move(gm->x, gm->y - 1, gm);
	else if (keycode == PRESS_S || keycode == DOWN)
		so_make_move(gm->x, gm->y + 1, gm);
	else if (keycode == PRESS_A || keycode == LEFT)
		so_make_move(gm->x - 1, gm->y, gm);
	else if (keycode == PRESS_D || keycode == RIGHT)
		so_make_move(gm->x + 1, gm->y, gm);
	return (0);
}

int	so_press_key(int keycode, t_mapconf *gm)
{
	static size_t	steps;

	if (so_move_player(keycode, gm))
		printf("step %zu\n", ++steps);
	fflush(NULL);
	return (0);
}
