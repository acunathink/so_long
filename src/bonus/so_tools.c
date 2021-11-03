/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:11:10 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/03 18:30:06 by ojospeh          ###   ########.fr       */
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
	else if (g->map[y][x] == 'G')
		mlx_put_image_to_window
		(g->mlx, g->window, g->img->ghost[g->ghost->n0][g->ghost->n1], \
					x * g->img->wid, y * g->img->hei);
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
				mlx_put_image_to_window(gm->mlx, gm->window, \
					gm->img->black, x * gm->img->wid, y * gm->img->hei);
				if (sprite == 'G')
				{
					gm->map[y][x] = gm->ghost->ex[0];
					so_put_image(x, y, gm);
					gm->map[y][x] = sprite;
				}
				so_put_image(x, y, gm);
			}
		}
	}
}

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

void	so_add_ghost(t_mapconf *gm, size_t y, size_t x)
{
	t_ghost	*new;
	t_ghost	*last;

	last = gm->ghost;
	new = (t_ghost *)malloc(sizeof(t_ghost));
	*new = (t_ghost)
	{.ex = {'0'}, .x = x, .y = y, .next = NULL, .n0 = 0, .n1 = 0};
	if (!gm->ghost)
		gm->ghost = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
