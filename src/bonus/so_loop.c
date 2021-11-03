/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:40:28 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/03 14:44:59 by ojospeh          ###   ########.fr       */
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

int		so_choise(size_t target, size_t hunter)
{
	if (target > hunter)
		return (++hunter);
	else if (target < hunter)
		return (--hunter);
	else
		return (hunter);
}

void	so_turn_choise(t_mapconf *gm, t_ghost *gst)
{
	size_t		turn_x;
	size_t		turn_y;

	turn_x = so_choise(gm->x, gst->x);
	turn_y = so_choise(gm->y, gst->y);
	gst->ex[1] = gm->map[turn_y][turn_x];
	gm->map[turn_y][turn_x] = 'G';
	gm->map[gst->y][gst->x] = gst->ex[0];
	gst->ex[0] = gst->ex[1];
	so_put_image((int)turn_x, (int)turn_y, gm);
	mlx_put_image_to_window(gm->mlx, gm->window, gm->img->black, \
			(int)(gst->x) * gm->img->wid, (int)(gst->y) * gm->img->hei);
	so_put_image(gst->x, gst->y, gm);
	gst->y = turn_y;
	gst->x = turn_x;
	if (gst->ex[1] == 'P')
	{
		mlx_string_put(gm->mlx, gm->window, gm->wid / 3, gm->hei / 3, 0x303133, "gotcha");
		ft_putendl_fd(RED "\n\t gotcha", 1);
	}
}

void	so_ghost_move(t_mapconf *gm)
{
	t_ghost	*gst;

	gst = gm->ghost;
	while (gst)
	{
		so_turn_choise(gm, gst);
		gst = gst->next;
	}
}

int	so_atloop(t_mapconf *gm)
{
	char			*step;
	static size_t	check;

	step = ft_itoa(gm->step);
//	printf(YELL "\n check = %zu" WHT, ++check);
	if (!(++check % 12))
	{
		so_print_sprite(gm, 'E');
		++gm->loop;
	}
	if (!(check % 60))
		so_ghost_move(gm);
	so_draw_count(gm, &step);
	free(step);
	return (0);
}
