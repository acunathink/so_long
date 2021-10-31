/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:00:59 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/31 18:53:27 by ojospeh          ###   ########.fr       */
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

void	so_print_image(t_mapconf *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int)game->row)
	{
		x = -1;
		while (++x < (int)game->col - 1)
			so_put_image(x, y, game);
	}
}

void	so_image_init(t_mapconf *game)
{
	t_images	*img;

	img = (t_images *)malloc(sizeof(t_images));
	*img = (t_images)
	{
		.wid = 32,
		.hei = 32,
		.colect = mlx_xpm_file_to_image(game->mlx, COLL, &img->wid, &img->hei),
		.wall = mlx_xpm_file_to_image(game->mlx, WALL, &img->wid, &img->hei),
		.grass = mlx_xpm_file_to_image(game->mlx, GRAS, &img->wid, &img->hei),
		.player = mlx_xpm_file_to_image(game->mlx, PLAY, &img->wid, &img->hei),
		.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &img->wid, &img->hei),
		.black = mlx_xpm_file_to_image(game->mlx, BLACK, &img->wid, &img->hei)
	};
	if (!img->colect || !img->wall || !img->grass || !img->player || !img->exit)
		exit(so_end_with_error("unable to use images"));
	game->img = img;
	so_print_image(game);
}

void	so_put_image(int x, int y, t_mapconf *g)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img->wall, x * g->img->wid, y * g->img->hei);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img->grass, x * g->img->wid, y * g->img->hei);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img->colect, x * g->img->wid, y * g->img->hei);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img->player, x * g->img->wid, y * g->img->hei);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img->exit, x * g->img->wid, y * g->img->hei);
}

int	so_close_game(int keycode, t_mapconf *gm)
{
	if (keycode == WINNER)
	{
		ft_putendl_fd(GRN "\n YOU are WINNER\n" WHT, 1);
		mlx_string_put(gm->mlx, gm->window, gm->wid / 3, gm->hei / 3, 0x90FFA0, \
		"YOU are WINNER");
		gm->map[gm->y - 1][gm->x] = '1';
		gm->map[gm->y + 1][gm->x] = '1';
		gm->map[gm->y][gm->x + 1] = '1';
		gm->map[gm->y][gm->x - 1] = '1';
		mlx_hook(gm->window, 17, 0, so_close_game, gm);
		mlx_loop(gm->mlx);
	}
	else
		ft_putendl_fd(RED "\nGAME OVER\n" WHT, 1);
	fflush(NULL);
	(void) gm;
	(void) keycode;
	exit(0);
}

void	so_long(t_mapconf *game)
{
	game->wid *= 32;
	game->hei = game->row * 32;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(so_end_with_error("mlx_init() fail"));
	game->window = mlx_new_window(game->mlx, game->wid, game->hei, "so_long");
	if (!game->window)
		exit(so_end_with_error("fail making new window"));
	so_image_init(game);
	mlx_key_hook(game->window, so_press_key, game);
	mlx_hook(game->window, 17, 0, so_close_game, game);
	mlx_loop(game->mlx);
}
