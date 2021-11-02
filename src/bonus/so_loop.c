/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:40:28 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/02 14:42:37 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_draw_count(t_mapconf *gm, char **step)
{
	int		x;
	int		y;
	int		mx;
	int		my;

	y = -1;
	while (++y < 1)
	{
		x = -1;
		while (++x < 4)
		{
			mlx_put_image_to_window(gm->mlx, gm->window, gm->img->black, \
									x * gm->img->wid, y * gm->img->hei);
			so_put_image(x, y, gm);
		}
	}
	mx = gm->img->wid / 3 - 2;
	my = gm->img->hei / 5;
	x = 0;
	while (++x <= (int)ft_strlen(*step))
		mlx_put_image_to_window(gm->mlx, gm->window, gm->img->undt, x * mx, my);
	mlx_string_put(gm->mlx, gm->window, mx + 3, my - 1, 0xfa6a03, *step);
}

int	so_atloop(t_mapconf *gm)
{
	char	*step;

	step = ft_itoa(gm->step);
	so_draw_count(gm, &step);
	return (0);
}
