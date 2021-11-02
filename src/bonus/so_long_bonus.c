/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:00:59 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/02 19:34:50 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	so_sprite_init(t_mapconf *g, void **sp, const char *path, int num)
{
	char	*sprite;

	sprite = ft_strdup(path);
	g->key = 0;
	while (g->key < 4)
	{
		sprite[num] = (char)(g->key + '0');
		printf(RED "\nsprite: %s" WHT, sprite);
		sp[g->key] = mlx_xpm_file_to_image(g->mlx, sprite, \
											&g->img->wid, &g->img->hei);
		if (!sp[g->key++])
			return (0);
	}
	free(sprite);
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
	if (!img->colect || !so_sprite_init(gm, &(img->player[0]), PLAY, 15) || \
		!img->grass || !so_sprite_init(gm, &(img->exit[0]), EXIT, 13) || \
		!img->wall)
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
	mlx_loop_hook(game->mlx, so_press_key, game);
	mlx_loop_hook(game->mlx, so_atloop, game);
	mlx_do_sync(game->mlx);
	mlx_loop(game->mlx);
}
