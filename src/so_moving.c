/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:57:34 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/03 19:44:26 by ojospeh          ###   ########.fr       */
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
		{
			--gm->colect;
			mlx_put_image_to_window(gm->mlx, gm->window, gm->img->black, \
								turn_x * gm->img->wid, turn_y * gm->img->hei);
		}
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
	return (0);
}

int	so_move_player(int keycode, t_mapconf *gm)
{
	if (keycode == PRESS_ESC)
		exit (so_close_game(keycode, gm));
	else if (keycode == PRESS_W || keycode == UP)
		return (so_make_move(gm->x, gm->y - 1, gm));
	else if (keycode == PRESS_S || keycode == DOWN)
		return (so_make_move(gm->x, gm->y + 1, gm));
	else if (keycode == PRESS_A || keycode == LEFT)
		return (so_make_move(gm->x - 1, gm->y, gm));
	else if (keycode == PRESS_D || keycode == RIGHT)
		return (so_make_move(gm->x + 1, gm->y, gm));
	else if (keycode == MAP)
		so_print_map(gm);
	else if (keycode == P)
		printf(YELL);
	else if (keycode == PK)
		++gm->key;
	else if (keycode == COLOR)
		ft_putstr_fd(WHT, 1);
	return (0);
}

int	so_press_key(int keycode, t_mapconf *gm)
{
	if (so_move_player(keycode, gm))
		printf("step %zu\n", ++gm->step);
	if (gm->key % 2)
		printf("\tkeycode: %d\n", keycode);
	fflush(NULL);
	return (0);
}

int	so_close_game(int keycode, t_mapconf *gm)
{
	if (keycode == WINNER)
	{
		ft_putendl_fd(GRN "\n YOU are WINNER\n" WHT, 1);
		mlx_string_put(gm->mlx, gm->window, gm->wid / 3, gm->hei / 3, 0xffc261, \
		"YOU are WINNER");
		gm->map[gm->y - 1][gm->x] = '1';
		gm->map[gm->y + 1][gm->x] = '1';
		gm->map[gm->y][gm->x + 1] = '1';
		gm->map[gm->y][gm->x - 1] = '1';
		mlx_hook(gm->window, 17, 0, so_close_game, gm);
		mlx_loop(gm->mlx);
	}
	else
		ft_putendl_fd(NAVY "\nsee you later..\n" WHT, 1);
	fflush(NULL);
	(void) gm;
	(void) keycode;
	exit(0);
}
