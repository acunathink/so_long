/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:00:59 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/03 18:26:24 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	so_sprite_init(t_mapconf *g, void **sp, const char *path, int num)
{
	char	*sprite;

	sprite = ft_strdup(path);
	sprite[num - 1] = g->key + '0';
	g->key = 0;
	while (g->key < 4)
	{
		sprite[num] = (char)(g->key + '0');
		sp[g->key] = mlx_xpm_file_to_image(g->mlx, sprite, \
											&g->img->wid, &g->img->hei);
		if (!sp[g->key++])
			return (0);
	}
	g->key = 0;
	free(sprite);
	return (1);
}

int	so_sprites_init(t_mapconf *g, t_images *img)
{
	int	line_s;

	line_s = 0;
	g->key = 0;
	if (!so_sprite_init(g, &(img->player[0]), PLAY, PLAY_NUM_AT) || \
		!so_sprite_init(g, &(img->exit[0]), EXIT, EXIT_NUM_AT))
		return (0);
	while (line_s < 2)
	{
		g->key = line_s;
		if (!so_sprite_init(g, &(img->ghost[line_s++][0]), GHOST, GHOST_NUM))
			return (0);
	}
	return (1);
}

void	so_image_init(t_mapconf *gm)
{
	t_images	*img;

	img = (t_images *)malloc(sizeof(t_images));
	*img = (t_images)
	{
		.wid = 32, .hei = 32, \
		.colect = mlx_xpm_file_to_image(gm->mlx, COLL, &img->wid, &img->hei), \
		.wall = mlx_xpm_file_to_image(gm->mlx, WALL, &img->wid, &img->hei), \
		.grass = mlx_xpm_file_to_image(gm->mlx, GRAS, &img->wid, &img->hei), \
		.black = mlx_xpm_file_to_image(gm->mlx, BLACK, &img->wid, &img->hei), \
		.undt = mlx_xpm_file_to_image(gm->mlx, UND_T, &img->wid, &img->hei)
	};
	gm->img = img;
	if (!img->colect || !img->grass || !img->wall || !so_sprites_init(gm, img))
		exit(so_end_with_error("unable to use images"));
	so_print_image(gm);
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
	mlx_loop_hook(game->mlx, so_atloop, game);
	mlx_do_sync(game->mlx);
	mlx_loop(game->mlx);
}
