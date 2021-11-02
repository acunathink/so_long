/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:11:10 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/02 19:35:37 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		(g->mlx, g->window, g->img->player[(3 + g->step) % 4], \
					g->img->wid * x, g->img->hei * y);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img->exit[g->loop % 4], \
					x * g->img->wid, y * g->img->hei);
}

void	so_print_sprite(t_mapconf *gm, char sprite)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (int)gm->row)
	{
		x = -1;
		while (++x < (int)gm->col - 1)
		{
			if (gm->map[y][x] == sprite)
			{
				mlx_put_image_to_window(gm->mlx, gm->window, gm->img->black, \
								x * gm->img->wid, y * gm->img->hei);
				so_put_image(x, y, gm);
			}
		}
	}
}
